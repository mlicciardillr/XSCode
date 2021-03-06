//
//###########################################################
//###     Make Calib. table and MPPC easy check file      ###
//###########################################################
//###                Made by M.Otani                      ###
//###########################################################

#include"Calc_MPPC_new_ci_2.hxx"
Int_t                 NumEvt;


void Analysis(){
  cout<<"analysis"<<endl;
  for(int irmm=0;irmm<5;irmm++){
    for(int itfb=0; itfb<48; itfb++){  
      for(int itrip=0;itrip < 4; itrip++){
	for(int itrip_ch=0;itrip_ch<16;itrip_ch++){
	  int imod, iview, ipln, numch;

	  if( !isPM(irmm, itfb) ){
	    if(!fINGRID_Ch_config->channel_configuration(&irmm,&itfb,&itrip,&itrip_ch,&imod,&iview,&ipln, &numch))
	      continue;
	  }	 
	  else if( isPM(irmm, itfb) ){
	    if(!fPM_Ch_config->channel_configuration(&irmm,&itfb,&itrip,&itrip_ch,&imod,&iview,&ipln, &numch))
	      continue;
	  }

	  int global_ch;
	  bool read = false;
	  if( !isPM(imod) )
	    if(fINGRID_Ch_config->get_global_ch(&imod,&iview,&ipln,&numch,&global_ch)&&
	       !fINGRID_BadCh_mapping->badchannel(imod, iview, ipln, numch) )
	      read = true;
	  if( isPM(imod) )
	    if(fPM_Ch_config->get_global_ch(&imod,&iview,&ipln,&numch,&global_ch) && 
	       !fINGRID_BadCh_mapping->badchannel(imod, iview, ipln, numch) )
	      read = true;
	  if(read){
	    GoodCh   [imod][iview][ipln][numch] = true;

	    fana_MPPC  -> analysis_old_version( fH_HighAdc[imod][iview][ipln][numch] );
	    fana_MPPC  -> analysis_logain     ( fH_LowAdc [imod][iview][ipln][numch] );

	    HighPed  [imod][iview][ipln][numch] = fana_MPPC -> get_pedestal                ();
	    LowPed   [imod][iview][ipln][numch] = fana_MPPC -> get_lowpedestal             ();
	    HighGain [imod][iview][ipln][numch] = fana_MPPC -> get_gain                    ();
	    MPPCNoise[imod][iview][ipln][numch] = fana_MPPC -> get_noise                   ();
	    MPPCCandA[imod][iview][ipln][numch] = fana_MPPC -> get_crosstalk_and_afterpulse();
	    TdcThre  [imod][iview][ipln][numch] 
	      = 1.0 * ( fMinAdcwTdcCut[imod][iview][ipln][numch] - HighPed[imod][iview][ipln][numch] )/HighGain[imod][iview][ipln][numch];
	    mod.     push_back( imod   );
	    view.    push_back( iview  );
	    pln.     push_back( ipln   );
	    ch.      push_back( numch  );
	    rmm.     push_back( irmm   );
	    tfb.     push_back( itfb   );
	    trip.    push_back( itrip  );
	    trip_ch. push_back( itrip_ch  );
	    gain.    push_back( HighGain[imod][iview][ipln][numch]  );
	    pedestal.push_back( HighPed [imod][iview][ipln][numch]  );
	    refgain.    push_back( HighGainRef[imod][iview][ipln][numch]  );
	    refpedestal.push_back( HighPedRef [imod][iview][ipln][numch]  );

	  
	  }//active channel
	}//numch
      }//ipln
    }//view
  }//imod
}


void Event(ND::TND280RawEvent* re) {

  ND::THandle<ND::TRunInfoBank> RunInfoBank;
  while ( RunInfoBank = re->GetMidasBank<ND::TRunInfoBank>("XRUN",RunInfoBank) ) {
    ND::TRunInfoBank& runinfo = re->UseMidasBank<ND::TRunInfoBank>("XRUN");
    NumEvt = runinfo.GetSeqNumber();
  }

  // Loop over all banks of type TTripTHitBank
  ND::THandle<ND::TTripTDigitBank> triptBank;
  while ( triptBank = re->GetMidasBank<ND::TTripTDigitBank>("",triptBank) ) {

    // Create an iterator over digits
    ND::TMidasTripTDigitItr itr(triptBank->GetMidasTripTDigitItr());
    while ( ! itr.EOD() ) {

      ND::TMidasTripTDigit digit(itr.Get());
      Int_t imod, iview, ipln, ich;
      Int_t irmm      = digit.GetRMMNum();
      Int_t itrip     = digit.GetTripTNum();
      Int_t itrip_ch  = digit.GetChannelNum();
      Int_t itfb      = digit.GetTFBNum();

      bool  read = false;
      if( !isPM(irmm, itfb) )
	if(fINGRID_Ch_config->channel_configuration(&irmm,&itfb,&itrip,&itrip_ch,&imod,&iview,&ipln, &ich))
	  read = true;
      if( isPM(irmm, itfb) )
	if(fPM_Ch_config->channel_configuration(&irmm,&itfb,&itrip,&itrip_ch,&imod,&iview,&ipln, &ich))
	  read = true;
      if(read){  // using channel
	Int_t highadc  =  digit.GetHighGainADC();
	Int_t loadc    =  digit.GetLowGainADC();
	long  tdc      =  digit.GetTimeOffset();
	fH_HighAdc[imod][iview][ipln][ich]  -> Fill(highadc);
	fH_LowAdc [imod][iview][ipln][ich]  -> Fill(loadc);
	NDChan [imod][iview][ipln][ich] = 100*(irmm*48+itfb)+16*itrip+itrip_ch;

	if( NumEvt  > 0             && 
	    tdc     < 16777201      && 
	    highadc < fMinAdcwTdcCut[imod][iview][ipln][ich]){
	  fMinAdcwTdcCut[imod][iview][ipln][ich] = highadc;
	}//Tdc threshold calibration

	 
      }
    }   // End of loop over digits in this bank
  }     // End of loop over banks of digits in this event

}
//____________________________________________________________________________


//____________________________________________________________________________
void ProcessFile(const char *FileName) {

  ND::TMidasFile mf;
  mf.Open(FileName);

  bool  exist_file = false;
  MakeHist();
  while ( ND::TND280RawEvent* re = mf.ReadRawEvent() ) {
    re -> PromoteMidasBanks(false);
    NumEvt = evtnum(re); 
    if(NumEvt%100==0)
      cout<< "Current event# = " << NumEvt << endl;

    if (NumEvt   == 0       ||  //### first event or
 	trgid(re)!= cAnaTrg     //### trigger for not analysis 
	){
      delete re;
      continue;
    }

    if( !exist_file ){//#### Start Calib. File #####
      /*Book( Form("/export/scraid2/data/bquilain/calib_root_file/ingrid_%08d_%04d_Calib%02d.root",
		 IngRun, IngSubRun, nCalib) );
      */
      Book( Form("/home/bquilain/calib_root_file/ingrid_%08d_%04d_Calib%02d.root",                                       
                 IngRun, IngSubRun, nCalib) );
      StartCalib(re);
      exist_file = true;
      nCalib++;
    }

    if(trgid(re) == cAnaTrg){
      Event(re);
      AnaEvt++;
    }

    if( AnaEvt >= ANABREAK ){ //### End of Calib. File
      EvtCheck   = true; 
      exist_file = false; //### flag for start Calib. File
      EndCalib (re);      //### Get End Time
      Analysis ();        //### Analyze MPPC gain and so on
      Close    ();        //### Write and Close ROOT file
      HistClear();        //### Clear the contents of Histogram for Analysis and ROOT file
      CLEAR();
    }
    delete re;

  }  // End loop over events
}

//_____________________________________________________________________________


int main(int argc,char *argv[]){
  TROOT          root("GUI","GUI");
  TApplication theApp("App",0,0);
 
  int      c =    -1;
  char FileName[300];
  Int_t pedestal_and_gain_for_cosmic;
  cAnaTrg=1;

  NumEvt=0;

  while ((c = getopt(argc, argv, "r:s:t:h")) != -1) {
    switch(c){

    case 'r':
      IngRun=atoi(optarg);
      break;
    case 's':
      IngSubRun=atoi(optarg);
      break;
    case 't':
      cAnaTrg=atoi(optarg);
      break;
    case 'h':
      cout<<"-r [run number]\n"<<endl;
      cout<<"-s [sub run number]\n"<<endl;
      cout<<"-t [trigger ID]\n"<<endl;
      exit(1);
      break;
    case '?':
      cout<<"Unknown option"<<endl;
      exit(1);
      break;
    }
  }//option end

  //sprintf(FileName,"%s/ingrid_%08d_%04d.daq.mid.gz",data_file_folder,IngRun,IngSubRun);
  //sprintf(FileName,"/export/scraid2/data/bquilain/Midas_All/ingrid_%08d_%04d.daq.mid.gz",IngRun,IngSubRun);
  sprintf(FileName,"/home/bquilain/ingrid_%08d_%04d.daq.mid.gz",IngRun,IngSubRun);
  cout << "file name is :" << FileName
       << endl;
  if ( gSystem->GetPathInfo(FileName,fs) ) {
    exit(0);
  }
  fana_MPPC             = new ana_MPPC();
  fINGRID_Ch_config     = new INGRID_Ch_config();
  fPM_Ch_config         = new PM_Ch_config();
  fINGRID_BadCh_mapping = new INGRID_BadCh_mapping();
  GetRef();
  nCalib=0;
  ProcessFile(FileName);

  //Close();
  return 0;
}


