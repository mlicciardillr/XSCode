#include"Calc_MPPC.hxx"


Int_t                 NumEvt;


void Analysis(){
  cout<<"analysis"<<endl;
  double pedestal,gain,noise,caa,lopedestal;
  for(Int_t nummod=0;nummod<NumMod;nummod++){
    for(Int_t view=0;view<2;view++){  
      for(Int_t numtfb=0;numtfb<NumTFB;numtfb++){
	for(Int_t numch=0;numch<24;numch++){

	  int global_ch;

	  bool tpl,veto;
	  int tmp;int tmpch;
	  if(numtfb>10){tpl=false;veto=true;tmp=numtfb-11;}
	  else {tpl=true;veto=false;tmp=numtfb;}
	  if(view==0&&tpl){tmpch=numch+24;}
	  else if(view==1&&tpl){tmpch=numch;}
	  else if(veto){tmpch=numch;}



	  if(fINGRID_Ch_config->get_global_ch(&nummod,&view,&numtfb,&numch,&global_ch)&&!fINGRID_BadCh_mapping->badchannel(nummod, view, numtfb, numch)){
	    GoodCh   [nummod][view][numtfb][numch] = true;
	    fana_MPPC  -> analysis_old_version( fH_HighAdc[nummod][view][numtfb][numch] );
	    fana_MPPC  -> analysis_logain     ( fH_LowAdc [nummod][view][numtfb][numch] );
	    /*########################Added by B.Quilain on 2013/03/05###############################*/
            HighADC [nummod][view][numtfb][numch] = fH_HighAdc[nummod][view][numtfb][numch]->GetMean();
            LowADC [nummod][view][numtfb][numch] = fH_LowAdc[nummod][view][numtfb][numch]->GetMean();

	    HighPed  [nummod][view][numtfb][numch] = fana_MPPC -> get_pedestal                ();
	    LowPed   [nummod][view][numtfb][numch] = fana_MPPC -> get_lowpedestal             ();
	    HighGain [nummod][view][numtfb][numch] = fana_MPPC -> get_gain                    ();
	    MPPCNoise[nummod][view][numtfb][numch] = fana_MPPC -> get_noise                   ();
	    MPPCCandA[nummod][view][numtfb][numch] = fana_MPPC -> get_crosstalk_and_afterpulse();

	    TdcThre  [nummod][view][numtfb][numch] 
	      = 1.0 * ( fMinAdcwTdcCut[nummod][view][numtfb][numch] - HighPed[nummod][view][numtfb][numch] )/HighGain[nummod][view][numtfb][numch];

	    /*
	    if( HighGain[nummod][view][numtfb][numch] < 0.5 || 
		HighGain[nummod][view][numtfb][numch] > 28  
		){
	    //if( nummod == 2 && view == 0 && numtfb == 8 && numch == 17 ){
	      TCanvas* c1 = new TCanvas("c1","c1", 10,10,600,600);
	      fH_HighAdc[nummod][view][numtfb][numch] -> Draw();
	      c1 -> Update();
	      cout << nummod << "\t"
		   << view   << "\t"
		   << numtfb << "\t"
		   << numch  << "\t"
		   << HighGain[nummod][view][numtfb][numch]
		   << endl;
	      cin.get();
	    }
	    */
	  
	  }//active channel
	}//numch
      }//numtfb
    }//view
  }//nummod

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
      Int_t mod, view, plane, ch;
      Int_t rmm      = digit.GetRMMNum();
      Int_t trip     = digit.GetTripTNum();
      Int_t trip_ch  = digit.GetChannelNum();
      Int_t tfb      = digit.GetTFBNum();
      if(fINGRID_Ch_config->channel_configuration(&rmm,&tfb,&trip,&trip_ch,&mod,&view,&plane, &ch)){  //### INGRID using channel
	Int_t highadc  =  digit.GetHighGainADC();
	Int_t loadc    =  digit.GetLowGainADC();
	long  tdc      =  digit.GetTimeOffset();
	fH_HighAdc[mod][view][plane][ch]  -> Fill(highadc);
	fH_LowAdc [mod][view][plane][ch]  -> Fill(loadc);

	if( NumEvt  > 0             && 
	    tdc     < 16777201      && 
	    highadc < fMinAdcwTdcCut[mod][view][plane][ch]){
	  fMinAdcwTdcCut[mod][view][plane][ch] = highadc;
	}//Tdc threshold calibration

	 
      }
    }   // End of loop over digits in this bank
  }     // End of loop over banks of digits in this event

}
//____________________________________________________________________________


//____________________________________________________________________________
void ProcessFile(const char *FileName) {
  
  //ND::TMidasBankProxyRegistry::Instance().Print();
  


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
      Book( Form("/home/bquilain/Ingrid_Process/calib_root_file/ingrid_%08d_%04d_Calib%02d.root",
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
      EndCalib(re);
      Analysis();
      //Analysis();
      fGainCheck  ();
      EvtCheck   = true;
      Close   ();
      HistClear();

      exist_file = false;
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

  while ((c = getopt(argc, argv, "hr:s:t:")) != -1) {
    switch(c){

    case 'r':
      IngRun=atoi(optarg);
      break;
    case 's':
      IngSubRun=atoi(optarg);
      break;
    case 'h':
      cout<<"-r [run number]\t midas file to root file"<<endl;
      break;
    case 't':
      cAnaTrg=atoi(optarg);
      break;
    case '?':
      cout<<"Unknown option"<<endl;

      exit(1);
      break;
    }
  }//option end

  sprintf(FileName,"/home/bquilain/Ingrid_Process/daqdata/ingrid_%08d_%04d.daq.mid.gz",
	  //data_file_folder,
	  IngRun,
	  IngSubRun);
  cout << "file name is :" << FileName
       << endl;
  if ( gSystem->GetPathInfo(FileName,fs) ) {
    exit(0);
  }
  fana_MPPC             = new ana_MPPC();
  fINGRID_Ch_config     = new INGRID_Ch_config();
  fINGRID_BadCh_mapping = new INGRID_BadCh_mapping();

  nCalib=0;
  ProcessFile(FileName);

  Close();
  return 0;
}


