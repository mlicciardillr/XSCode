#ifndef __INGEVTDISP_CXX__
#define __INGEVTDISP_CXX__
#include "IngEvtDisp.hxx"
#define LIMIT_SMALL
bool IngEvtDisp::Draw_Module(TCanvas& canvas, int mod = 0){
  ntrack_x =0;
  ntrack_y =0;
  fStyle =  new TStyle();
  fStyle -> SetStatStyle(0000);
  fStyle -> SetOptStat(0);
  fStyle -> SetTitleOffset(1.0,"X");
  fStyle -> SetTitleOffset(1.0,"Y");
  fStyle -> SetTitleH(0.08);
  fStyle -> SetTitleW(0.95);
  char buff[300];
  Int_t zend = PlnThick*NumPln + IronThick*NIron;

  fPSideView    =  new TPad("X","X",      0.0 , 0.0, 0.5 ,0.9);
  fPSideView    -> SetBit(kCanDelete);

  fPTopView     =  new TPad("Y","Y",      0.5 , 0.0, 1.0 ,0.9);
  fPInfo        =  new TPad("Info","Info",0.0 , 0.9, 1.0 ,1.0);
  fStyle   -> cd();
  canvas.     cd();


  fPSideView->Draw();
  fStyle -> cd();
  fPTopView->Draw();
  fStyle -> cd();
  fPInfo -> Draw();
  fStyle -> cd();
  //############### X View ####################
  //###########################################
  canvas.        cd();
  fPSideView    -> cd();
  sprintf(buff," Side View ");
  fHSideView    =  new TH1F(buff,buff,10*(zend+40),-20,zend+20);
  fHSideView    -> SetBit(kCanDelete);
  fHSideView    -> SetMinimum(-6*ScintiWidth);
  fHSideView    -> SetMaximum(ScintiWidth*(Nscinti+6));
  fHSideView    -> Draw();
  //Scintillater
  TBox *fBXScinti         =  new TBox(0,0, zend, ScintiWidth*Nscinti);
  fBXScinti               -> SetBit(kCanDelete);
  fBXScinti               -> SetFillColor(75);
  fBXScinti               -> Draw();
  for(Int_t i=0; i<Nscinti; i++){
    TLine *TLscinti       =  new TLine(0,ScintiWidth*i, zend, ScintiWidth*(i));
    TLscinti              -> SetBit(kCanDelete);
    TLscinti              -> SetLineWidth(1);
    TLscinti              -> SetLineColor(1);
    TLscinti              -> Draw();
  }

  //Iron
  for(Int_t i=0; i<NIron; i++){
    Double_t Thick        = IronThick + PlnThick;
    TBox *fBXIron         =  new TBox(i*Thick+PlnThick, 0, i*Thick+PlnThick+IronThick, ScintiWidth*Nscinti);
    fBXIron               -> SetBit(kCanDelete);
    fBXIron               -> SetFillColor(43);
    if(i==NIron-1)fBXIron->SetFillColor(0);
    fBXIron               -> Draw();
  }
  //Gap
  TBox*  fBXGap[NIron+1][2];
  for(Int_t i=0; i<NIron+1; i++){
    Double_t Thick        = IronThick + PlnThick;
    fBXGap [i][0]           =  new TBox(PlnThick + i*Thick - PlnThick,                         0,
					PlnThick + i*Thick - PlnThick + 2.1, ScintiWidth*Nscinti);
    fBXGap [i][0]           -> SetFillColor(0);
    fBXGap [i][0]           -> Draw();

    fBXGap [i][1]           =  new TBox(PlnThick + i*Thick - PlnThick + 3.1,                   0,
					PlnThick + i*Thick - PlnThick + PlnThick, ScintiWidth*Nscinti);
    fBXGap [i][1]           -> SetFillColor(0);
    fBXGap [i][1]           -> Draw();
					
  }

  //##### Bottom and UP VETO ###### 2010/5
  TBox *fBBVScinti        =  new TBox(    0, fVetoXY(mod, BVETO)    , 
				       zend, fVetoXY(mod,BVETO)+ScintiThick);
  fBBVScinti               -> SetBit(kCanDelete);
  fBBVScinti               -> SetFillColor(75);
  fBBVScinti               -> Draw();
  for(Int_t i=0; i<NscintiVETO; i++){
    TLine *TLscinti       =  new TLine( ScintiWidth*i    , fVetoXY(mod, BVETO),
					ScintiWidth*i    , fVetoXY(mod, BVETO)+ScintiThick);
    TLscinti              -> SetBit(kCanDelete);
    TLscinti              -> SetLineWidth(1);
    TLscinti              -> SetLineColor(1);
    TLscinti              -> Draw();
  }
  TBox *fBUVScinti        =  new TBox(    0, fVetoXY(mod,UVETO)    , 
				       zend, fVetoXY(mod,UVETO)+ScintiThick);
  fBUVScinti               -> SetBit(kCanDelete);
  fBUVScinti               -> SetFillColor(75);
  fBUVScinti               -> Draw();
  for(Int_t i=0; i<NscintiVETO; i++){
    TLine *TLscinti       =  new TLine( ScintiWidth*i    , fVetoXY(mod, UVETO),
					ScintiWidth*i    , fVetoXY(mod, UVETO)+ScintiThick);
    TLscinti              -> SetBit(kCanDelete);
    TLscinti              -> SetLineWidth(1);
    TLscinti              -> SetLineColor(1);
    TLscinti              -> Draw();
  }



  //############### Y View ####################
  //###########################################
  canvas        .cd();
  fPTopView    -> cd();
  sprintf(buff," Top View");
  fHTopView    =  new TH1F(buff,buff,10*(zend+40),-20,zend+20);
  fHTopView    -> SetBit(kCanDelete);
  fHTopView    -> SetMinimum(-6*ScintiWidth);
  fHTopView    -> SetMaximum(ScintiWidth*(Nscinti+6));
  fHTopView    -> Draw();
  //Scintillater
  TBox *fBYScinti         =  new TBox(0,0, zend, ScintiWidth*Nscinti);
  fBYScinti               -> SetBit(kCanDelete);
  fBYScinti               -> SetFillColor(75);
  fBYScinti               -> Draw();
  for(Int_t i=0; i<Nscinti; i++){
    TLine *TLscinti       =  new TLine(0,ScintiWidth*i, zend, ScintiWidth*(i));
    TLscinti              -> SetBit(kCanDelete);
    TLscinti              -> SetLineWidth(1);
    TLscinti              -> SetLineColor(1);
    TLscinti              -> Draw();
  }

  //Iron
  for(Int_t i=0; i<NIron; i++){
    Double_t Thick        = IronThick + PlnThick;
    TBox *fBYIron         =  new TBox(i*Thick+PlnThick, 0, i*Thick+PlnThick+IronThick, ScintiWidth*Nscinti);
    fBYIron               -> SetBit(kCanDelete);
    fBYIron               -> SetFillColor(43);
    if(i==NIron-1)fBYIron->SetFillColor(0);
    fBYIron               -> Draw();
  }

  TBox*  fBYGap[NIron+1][2];
  for(Int_t i=0; i<NIron+1; i++){
    Double_t Thick        = IronThick + PlnThick;
    fBYGap [i][0]           =  new TBox(PlnThick + i*Thick - PlnThick,                         0,
					PlnThick + i*Thick - PlnThick + 1.1, ScintiWidth*Nscinti);
    fBYGap [i][0]           -> SetFillColor(0);
    fBYGap [i][0]           -> Draw();

    fBYGap [i][1]           =  new TBox(PlnThick + i*Thick - PlnThick + 2.1,                   0,
					PlnThick + i*Thick - PlnThick + PlnThick, ScintiWidth*Nscinti);
    fBYGap [i][1]           -> SetFillColor(0);
    fBYGap [i][1]           -> Draw();
  }
  //##### Line Defined ######
  char name[300];
  for(int i=0; i<10; i++){
    sprintf(name,"X_Track%0d",i);
    fFtrack_x[i] = new TF1(name, "pol1", 0, 120);
    sprintf(name,"Y_Track%0d",i);
    fFtrack_y[i] = new TF1(name, "pol1", 0, 120);
  }

  //##### Right and Left VETO ###### 2010/5
  TBox *fBRVScinti        =  new TBox(    0, fVetoXY(mod, RVETO)    , 
				       zend, fVetoXY(mod,RVETO)+ScintiThick);
  fBRVScinti               -> SetBit(kCanDelete);
  fBRVScinti               -> SetFillColor(75);
  fBRVScinti               -> Draw();
  for(Int_t i=0; i<NscintiVETO; i++){
    TLine *TLscinti       =  new TLine( ScintiWidth*i    , fVetoXY(mod, RVETO),
					ScintiWidth*i    , fVetoXY(mod, RVETO)+ScintiThick);
    TLscinti              -> SetBit(kCanDelete);
    TLscinti              -> SetLineWidth(1);
    TLscinti              -> SetLineColor(1);
    TLscinti              -> Draw();
  }
  TBox *fBLVScinti        =  new TBox(    0, fVetoXY(mod,LVETO)    , 
				       zend, fVetoXY(mod,LVETO)+ScintiThick);
  fBLVScinti               -> SetBit(kCanDelete);
  fBLVScinti               -> SetFillColor(75);
  fBLVScinti               -> Draw();
  for(Int_t i=0; i<NscintiVETO; i++){
    TLine *TLscinti       =  new TLine( ScintiWidth*i    , fVetoXY(mod, LVETO),
					ScintiWidth*i    , fVetoXY(mod, LVETO)+ScintiThick);
    TLscinti              -> SetBit(kCanDelete);
    TLscinti              -> SetLineWidth(1);
    TLscinti              -> SetLineColor(1);
    TLscinti              -> Draw();
  }



  return true;
}

bool IngEvtDisp::Draw_Hit( Ingrid1stReducSummary& reduc,
			   double msize){
 
  int  mod = reduc.hitmod;
  int  cyc = reduc.hitcyc;
  Int_t nhitx = 0;
  Int_t nhity = 0;
  fTMVecX.clear();
  fTMVecY.clear();
  int nhits = reduc.nhits;
  for(Int_t i=0; i<nhits; i++){
    IngridHitSummary* inghit = (IngridHitSummary*)reduc.GetIngridHit(i);
    //############## X View ##################
    //########################################
    fPSideView -> cd();
    if(inghit->view == 0 ){
      float x = inghit->xy;
      float z = inghit->z;
      if(inghit->pln<=10){//### TPL
	Double_t fSize = msize * inghit->pe;
	if(fSize>2.)fSize=2.;
	if(fTMdepX){
	  fTMdepX->Clear();
	  delete   fTMdepX;
	}
	fTMdepX =  new TMarker(z+0.5*PlnThick+0.5 ,x+0.5*ScintiWidth ,20);
	fTMdepX -> SetMarkerSize(fSize);
	fTMdepX -> SetMarkerColor(2);
	fTMVecX.push_back(*fTMdepX); nhitx++;
	if(fSize>0.1)fTMVecX[nhitx-1].Draw();

      }
      else if( inghit->pln == BVETO || 
	       inghit->pln == UVETO ){
	Double_t fSize = msize * inghit->pe;
	if(fSize>2.)fSize=2.;
	if(fTMdepX){
	  fTMdepX->Clear();
	  delete   fTMdepX;
	}
	x = fVetoXY( inghit->mod, inghit->pln );
	fTMdepX = new TMarker(z+0.5*ScintiWidth ,x+0.5 ,20);
	fTMdepX -> SetMarkerSize(fSize);
	fTMdepX -> SetMarkerColor(2);
	fTMVecX.push_back(*fTMdepX); nhitx++;
	if(fSize>0.1)fTMVecX[nhitx-1].Draw();
      }
    }
    //############## Y View ##################
    //########################################

    else if( inghit->view == 1 ){
	     
      fPTopView->cd();
      float y = inghit->xy;
      float z = inghit->z;
      if( inghit->pln <= 10 ){
	Double_t fSize = msize * inghit->pe;
	if(fSize>2.)fSize=2.;
	if(fTMdepY){
	  fTMdepY->Clear();
	  delete   fTMdepY;
	}
	fTMdepY = new TMarker(z+0.5*PlnThick-0.5 ,y+0.5*ScintiWidth ,20);
	fTMdepY -> SetMarkerSize(fSize);
	fTMdepY -> SetMarkerColor(2);
	fTMVecY.push_back(*fTMdepY); nhity++;
	if(fSize>0.1)fTMVecY[nhity-1].Draw();
      }
      else if( inghit->pln == RVETO ||
	       inghit->pln == LVETO ){
	Double_t fSize = msize * inghit->pe;
	if(fSize>2.)fSize=2.;
	if(fTMdepY){
	  fTMdepY->Clear();
	  delete   fTMdepY;
	}
	y = fVetoXY( inghit->mod, inghit->pln );
	fTMdepY = new TMarker(z+0.5*ScintiWidth ,y+0.5 ,20);
	fTMdepY -> SetMarkerSize(fSize);
	fTMdepY -> SetMarkerColor(2);
	fTMVecY.push_back(*fTMdepY); nhity++;
	if(fSize>0.1)fTMVecY[nhity-1].Draw();
      }
    }
  }
}
bool IngEvtDisp::Draw_BeamInfo( BeamInfoSummary& beam ){
  char buff[300];
  fPInfo        -> cd();
  sprintf(buff,
	  "Spill# %0d, Time %0d",
	  beam.spillnum, beam.trg_sec);
 if(!fLatexBeamInfo){
    fLatexBeamInfo = new TLatex(0.01,0.6, buff);
  }
 
  fLatexBeamInfo -> SetText(0.01, 0.6, buff);
  fLatexBeamInfo -> SetTextSize(0.3);
  fLatexBeamInfo -> Draw();
}


bool IngEvtDisp::Draw_Line( TF1& line, int view, float iz, float fz ,
			    int color=1, int size=1){
  iz -= 1;
  fz += 1;
  if( view == 0 ){  //## Y view
    fPSideView -> cd();

    //fFtrack_x[ntrack_x] -> SetParameter(0, line.GetParameter(0) );
    fFtrack_x[ntrack_x] -> SetParameter(0, line.GetParameter(0)+0.5*ScintiWidth );
    fFtrack_x[ntrack_x] -> SetParameter(1, line.GetParameter(1) );
    fFtrack_x[ntrack_x] -> SetLineWidth(1);
    fFtrack_x[ntrack_x] -> SetRange(iz, fz);
    fFtrack_x[ntrack_x] -> SetLineColor(color);
    fFtrack_x[ntrack_x] -> SetLineWidth(size);
    fFtrack_x[ntrack_x] -> SetLineWidth(5);
    fFtrack_x[ntrack_x] -> Draw("same");
  
    ntrack_x++;


  }
  if( view == 1 ){  //## Y view
    fPTopView  -> cd();
    //fFtrack_y[ntrack_y] -> SetParameter(0, line.GetParameter(0) );
    fFtrack_y[ntrack_y] -> SetParameter(0, line.GetParameter(0)+0.5*ScintiWidth );
    fFtrack_y[ntrack_y] -> SetParameter(1, line.GetParameter(1) );
    fFtrack_y[ntrack_y] -> SetLineWidth(1);
    fFtrack_y[ntrack_y] -> SetRange(iz, fz);
    fFtrack_y[ntrack_y] -> SetLineColor(color);
    fFtrack_y[ntrack_y] -> SetLineWidth(size);
    fFtrack_y[ntrack_y] -> SetLineWidth(5);
    fFtrack_y[ntrack_y] -> Draw("same");
    
    ntrack_y++;
   
  }
}
bool IngEvtDisp::reset_track(){
  for(int i=0; i<ntrack_x; i++){
    fFtrack_x[i] -> Clear();
  }
  for(int i=0; i<ntrack_y; i++){
    fFtrack_y[i] -> Clear();
  }
  ntrack_x=0;
  ntrack_y=0;

}


bool IngEvtDisp::Draw_Line_all(){
  for(int i=0; i<fTFlineX.size(); i++){
    fPSideView -> cd();
    float ncons = fTFlineX[i] .GetParameter(0); 
    ncons      += 0.5*ScintiWidth;
    fTFlineX[i] . SetParameter(0, ncons);
    fTFlineX[i] . Draw("same");

  }
  for(int i=0; i<fTFlineY.size(); i++){
    fPTopView -> cd();
    float ncons = fTFlineY[i] .GetParameter(0); 
    ncons      += 0.5*ScintiWidth;
    fTFlineY[i] . SetParameter(0, ncons);

    fTFlineY[i] . Draw("same");
  }


}


template <class T> bool IngEvtDisp::Print_Hit_A(T& sum){

  for(Int_t i=0; i<sum.Nhits(); i++){
    IngridHitSummary* inghit = (IngridHitSummary*)sum.GetIngridHit(i);
    if(inghit==0)continue;
    cout << "view: " << inghit->view   << "\t"
	 << "pln : " << inghit->pln    << "\t"
	 << "ch  : " << inghit->ch     << "\t"
	 << "pe  : " << inghit->pe     << "\t"
	 << "time  : " << inghit->time << "\t"
	 << endl;
  }
}

bool IngEvtDisp::Draw_Muon(IngridEventSummary& evt){
  cout << "------ Draw Muon Info ----------" << endl;
  int nmu = 0;
  for(Int_t ipar=0; ipar<evt.NIngridSimParticles(); ipar++){
    IngridSimParticleSummary* simpar = (IngridSimParticleSummary*)evt.GetSimParticle(ipar);

    if(simpar->pdg!=13)continue;
    
 
    float ax     =  simpar->dir[0]/simpar->dir[2];
    float ay     =  simpar->dir[1]/simpar->dir[2];
    float verx   =  simpar -> ipos[0];
    float very   =  simpar -> ipos[1];
    float verz   =  simpar -> ipos[2];
    float endx   =  simpar -> fpos[0];
    float endy   =  simpar -> fpos[1];
    float endz   =  simpar -> fpos[2];
    if(verz > -100){//H module
      int hitmod = (int)((verx+525)/150);
      verx       = verx + 525 - 150*hitmod-15+2.5;
      very       = very + 60 + 2.5;
      verz       = verz + 54.5 ;
      endx       = endx + 525 - 150*hitmod-15+2.5;
      endy       = endy + 60+2.5;
      endz       = endz + 54.5 ;
    }
    else{
      int hitmod = (int)((very+525)/150);
      very       = very + 525 - 150*hitmod-15 + 2.5;
      verx       = verx + 60 + 2.5;
      verz       = verz + 454.5 ;
      endy       = endy + 525 - 150*hitmod-15 + 2.5;
      endx       = endx + 60 + 2.5;
      endz       = endz + 454.5 ;
    }
    cout << verx << "\t" << very << "\t" << verz <<endl;
    float bx     =  verx - ax * verz; 
    float by     =  very - ay * verz; 
    
    mutrkx[nmu]  =  new TF1( Form("mutrkx%d",nmu), "pol1", verz, endz  );
    mutrkx[nmu]  -> SetParameter(0, bx);  
    mutrkx[nmu]  -> SetParameter(1, ax);  
    mutrky[nmu]  =  new TF1( Form("mutrky%d",nmu), "pol1", verz, endz  );
    mutrky[nmu]  -> SetParameter(0, by);  
    mutrky[nmu]  -> SetParameter(1, ay);
    mutrkx[nmu]  -> SetLineWidth(3);
    mutrky[nmu]  -> SetLineWidth(3);
    mutrkx[nmu]  -> SetLineColor(607);
    mutrky[nmu]  -> SetLineColor(607);
    mutrkx[nmu]  -> SetLineStyle(2);
    mutrky[nmu]  -> SetLineStyle(2);
 
    fPTopView    -> cd();
    mutrkx[nmu]  -> Draw("same");
    fPSideView   -> cd();
    mutrky[nmu]  -> Draw("same");
    nmu++;
  

  }
}

bool IngEvtDisp::Print_Muon(IngridEventSummary& evt){
  cout << "------ Print Muon Info ----------" << endl;
  int nmuon = 0;
  for(Int_t ipar=0; ipar<evt.NIngridSimParticles(); ipar++){
    IngridSimParticleSummary* simpar = (IngridSimParticleSummary*)evt.GetSimParticle(ipar);
   
    if(simpar->pdg!=13)continue;
    nmuon++;
    cout << "-- " << nmuon << " th muon -----" << endl;
    cout << " Energy  : " << simpar -> momentum[3] + 0.106 << endl;
   

  }
}


int noisecolor = 4;
template <class T> bool IngEvtDisp::Draw_Hit_A(T& sum,
					       double msize,
					       int color=2,
					       int flag =1)

{

  int hitmod=-1;
  int nhitx;
  int nhity;
  if(flag){
    nhitx = 0;
    nhity = 0;
    fTMVecX.clear();
    fTMVecY.clear();
  }
  else{
    nhitx = fTMVecX.size();
    nhity = fTMVecY.size();
  }


  for(Int_t i=0; i<sum.Nhits(); i++){

    IngridHitSummary* inghit = (IngridHitSummary*)sum.GetIngridHit(i);
    if(inghit==0)continue;
    //if(hitmod==-1)hitmod = inghit->mod;


    //############## X View ##################
    //########################################
    if(inghit->view == 0 ){
      fPSideView -> cd();
      float x = inghit->xy;
      float z = inghit->z;
      if(inghit->pln<=10){//### TPL
	Double_t fSize = msize * inghit->pe;

	if(fSize>2.)fSize=2.;
#ifdef LIMIT_SMALL
	if(fSize<0.6)fSize=0.6;
#endif

	if(fTMdepX){
	  //fTMdepX->Clear();
	  //delete   fTMdepX;
	}
	fTMdepX =  new TMarker(z+0.5*PlnThick+0.5 ,x+0.5*ScintiWidth ,20);
	fTMdepX -> SetMarkerSize(fSize);
	fTMdepX -> SetMarkerColor(color);
	if( inghit->dummy )	fTMdepX -> SetMarkerColor(noisecolor);
	fTMVecX.push_back(*fTMdepX); nhitx++;
	/*
	cout <<"draw view" << inghit -> view
	     <<"\tpln"     << inghit -> pln
	     <<"\tch"      << inghit -> ch
	     <<"\txy "     << inghit -> xy
	     <<"\tz"       << inghit -> z
	     <<"\tpe"      << inghit -> pe
	     <<"\tnhitx"   << nhitx 
	     <<"\tsize"   << fTMVecX.size()
	     <<endl;
	*/
	//if(fSize>0.1)
	fTMdepX -> Draw();
	fTMVecX[nhitx-1].Draw();
      }
      else if( inghit->pln == BVETO || 
	       inghit->pln == UVETO ){
	Double_t fSize = msize * inghit->pe;
	if(fSize>2.)fSize=2.;
	if(fTMdepX){
	  //fTMdepX->Clear();
	  //delete   fTMdepX;
	}
	x = fVetoXY( inghit->mod, inghit->pln );
	fTMdepX = new TMarker(z+0.5*ScintiWidth ,x+0.5 ,20);
	fTMdepX -> SetMarkerSize(fSize);
	fTMdepX -> SetMarkerColor(color);
	if( inghit->dummy )	fTMdepX -> SetMarkerColor(noisecolor);
	fTMVecX.push_back(*fTMdepX); nhitx++;
	//if(fSize>0.1)
	fTMdepX -> Draw();
	fTMVecX[nhitx-1].Draw();
      }
    }
    //############## Y View ##################
    //########################################

    else if( inghit->view == 1 ){

      fPTopView->cd();
      float y = inghit->xy;
      float z = inghit->z;
      if( inghit->pln <= 10 ){
	Double_t fSize = msize * inghit->pe;
	if(fSize>2.)fSize=2.;
#ifdef LIMIT_SMALL
	if(fSize<0.6)fSize=0.6;
#endif
	if(fTMdepY){
	  //fTMdepY->Clear();
	  //delete   fTMdepY;
	}
	fTMdepY = new TMarker(z+0.5*PlnThick-0.5 ,y+0.5*ScintiWidth ,20);
	fTMdepY -> SetMarkerSize(fSize);
	fTMdepY -> SetMarkerColor(color);
	if( inghit->dummy )	fTMdepY -> SetMarkerColor(noisecolor);
	fTMVecY.push_back(*fTMdepY); nhity++;
	//if(fSize>0.1)
	fTMdepY -> Draw();
	fTMVecY[nhity-1].Draw();

      }
      else if( inghit->pln == RVETO ||
	       inghit->pln == LVETO ){
	Double_t fSize = msize * inghit->pe;
	if(fSize>2.)fSize=2.;
	if(fTMdepY){
	  //fTMdepY->Clear();
	  //delete   fTMdepY;
	}
	y = fVetoXY( inghit->mod, inghit->pln );
	fTMdepY = new TMarker(z+0.5*ScintiWidth ,y+0.5 ,20);
	fTMdepY -> SetMarkerSize(fSize);
	fTMdepY -> SetMarkerColor(color);
	if( inghit->dummy )	fTMdepY -> SetMarkerColor(noisecolor);
	fTMVecY.push_back(*fTMdepY); nhity++;
	//if(fSize>0.1)
	fTMdepY -> Draw();
	fTMVecY[nhity-1].Draw();

      }
    }
  }//Nhits

  char buff[300]; 
  fPInfo        -> cd();
  sprintf(buff,
	  "Module %0d",
	  hitmod);
  if(!fLatexModInfo){
    fLatexModInfo = new TLatex(0.01,0.3, buff);
  }
  fLatexModInfo -> SetText(0.01, 0.3, buff);
  fLatexModInfo -> SetTextSize(0.3);
  fLatexModInfo -> Draw();

  return true;
}


#endif
