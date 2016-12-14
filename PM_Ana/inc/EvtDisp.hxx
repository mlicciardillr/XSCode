#ifndef __ANA_COSMIC_HXX__
#define __ANA_COSMIC_HXX__

// ROOT includes
#include "TApplication.h"
#include "TFile.h"
#include "TH1F.h"
#include "TF1.h"
#include "TGraph.h"
#include "TH2F.h"
#include "TCanvas.h"
#include <TStyle.h>
#include "TString.h"
#include "TSystem.h"
#include "TSpectrum.h"
#include "TBox.h"
#include "TTree.h"
//C++ libraly includes
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip.h>
#include <algorithm>
#include <deque>
#include <vector>
#include <sys/stat.h>
#include <unistd.h> // using getopt      
using namespace std;
// INGRID includes
#include "setup.hxx"
#include "INGRID_Dimension.cxx"

const static Int_t   cNumMod    = 14;
const static Int_t   cNumTPL    = 11;
const static Int_t   cNumVeto   =  4;
const static Int_t   cNumCh     = 24;
const static Int_t   cNumLyr    =  2;
const static Int_t   cNumCyc    = 23;
const static Int_t   cTrgBeam   =  1;
const static Int_t   cTrgCalib  =  2;
const static Int_t   cTrgCosmic =128;
const static Int_t   NumPln     =11;
const static Int_t   NIron     =10;
const static Int_t   Nscinti     =24;
const static Int_t   XLyr     =0;
const static Int_t   YLyr     =1;
static Double_t msize     = 0.01;
INGRID_Dimension *fINGRID_Dimension;
//__________________________________________________________
//Int_t                 NumEvt;
Int_t                 TrgId;
Int_t                 cAnaEvt;
Int_t                 cAnaTrg;
Int_t                 cAnaMod;


class Hit{
public:
  Int_t      pln;
  Int_t     view;
  Int_t       ch;
  Int_t      adc;
  Float_t     pe;   //p.e.
  Long_t     tdc;  
  //Long_t    nsec;  
  Long_t    time;   //nsec
};


bool withtdc(const Hit& left, const Hit& right){
  return left.tdc > right.tdc;
};
bool withtime(const Hit& left, const Hit& right){
  return left.time < right.time;
};
bool withview(const Hit& left, const Hit& right){
  return left.view < right.view;
};

bool withpln(const Hit& left, const Hit& right){
  return left.pln < right.pln;
};
bool withch(const Hit& left, const Hit& right){
  return left.ch < right.ch;
};

bool fSortTdc(vector<Hit> &a){
  std::stable_sort(a.begin(), a.end(), withtdc);
};
bool fSortTime(vector<Hit> &a){
  std::stable_sort(a.begin(), a.end(), withtime);
};
bool fSortPln(vector<Hit> &a){
  std::stable_sort(a.begin(), a.end(), withpln);
};

const static Double_t cTimeRsr = 30; //nsec

void Print(vector<Hit> hit[][cNumCyc], Int_t nummod, Int_t numcyc){
  for(int i=0;i<hit[nummod][numcyc].size();i++){
    cout<<"pln:"   <<hit[nummod][numcyc][i].pln
	<<"\tview:"<<hit[nummod][numcyc][i].view
	<<"\tch:"  <<hit[nummod][numcyc][i].ch
	<<"\tadc:" <<hit[nummod][numcyc][i].adc
	<<"\tpe:"  <<hit[nummod][numcyc][i].pe
	<<"\ttdc:" <<hit[nummod][numcyc][i].tdc
	<<"\ttime:" <<hit[nummod][numcyc][i].time
	<<endl;
  }
  cin.get();
}
void Print(vector<Hit> hit){
  for(int i=0;i<hit.size();i++){
    cout<<"pln:"   <<hit[i].pln
	<<"\t view:"<<hit[i].view
	<<"\t ch:"  <<hit[i].ch
	<<"\t adc:" <<hit[i].adc
	<<"\t pe:"  <<hit[i].pe
	<<"\t tdc:" <<hit[i].tdc
	<<"\t time:" <<hit[i].time
	<<endl;
  }

}

Int_t cTdcRsr = 20; // 30nsec/2

bool fFindTimeClster(vector<Hit> &hit, vector<Hit> &hitclster, Long_t &time){
  //before using this function please fSortTdc
  Int_t nhit = hit.size();
  if(nhit < 2)return false;
  for(Int_t i=1 ; i<nhit-1; i++){
    if( (fabs( hit[i].time - hit[i-1].time) < cTdcRsr-5 &&
	 fabs( hit[i].time - hit[i+1].time) < cTdcRsr-5 )   ){
      Long_t basetime = hit[i].time;
      time = basetime;
      //degug 1
      /*
      Float_t start = hit[0].time;
      Float_t end   = hit[nhit-1].time;
      cout<<hit[i].time<<"\t"<<start<<"\t"<<end<<endl;
      Int_t range = end - start;
      TH1F *h1 = new TH1F("h1","h1",range/10, start, end);
      for(Int_t j=0 ; j<nhit; j++){
	h1->Fill(hit[j].time);
      }
      */


      vector<Hit>::iterator it;
      Int_t ncount=0;
      for(it = hit.begin() ; it != hit.end(); it++){
	if( fabs( basetime - it->time) < cTdcRsr ){
	  ncount++;
	}
      }
      if(ncount<=3)break;

      for(it = hit.begin() ; it != hit.end(); it++){
	if( fabs( basetime - it->time) < cTdcRsr ){
	  hitclster.push_back(*it);
	  it = hit.erase(it);
	  it--;
	}
      }


      //degug 1
      /*
      TH1F *h2 = new TH1F("h2","h2",range/10, start, end);
      for(Int_t j=0 ; j<hitclster.size(); j++){
	h2->Fill(hitclster[j].time);
      }
      TCanvas *c1 = new TCanvas("c1","c1",10,10,500,500);
      h1->SetLineWidth(3);
      h1->Draw();
      h2->SetLineColor(2);
      h2->Draw("same");
      c1->Update();
      h1->Reset();
      h2->Reset();
      delete h1;
      delete h2;
      */

      return true;
    }
  }//i
  return false;
}
//__________________________________________________________

TH1F *fHMviewX;
TH1F *fHMviewY;
TPad *fPMviewX;
TPad *fPMviewY;
TCanvas *fCMcanvas;
void Draw_Module(){
  char buff[300];
  Int_t zend = PlnThick*NumPln + IronThick*NIron;
  fCMcanvas = new TCanvas("fCMcanvas","fCMcanvas",10,10,500,500);
  fPMviewX    =  new TPad("X","X",0.0 , 0.5, 1.0 ,1.0);
  fPMviewX          -> SetBit(kCanDelete);
  fPMviewY    =  new TPad("Y","Y",0.0 , 0.0, 1.0 ,0.5);

  fCMcanvas->cd();
  fPMviewX->Draw();
  fPMviewY->Draw();

  //############### X View ####################
  //###########################################
  fCMcanvas->cd();
  fPMviewX    -> cd();
  sprintf(buff,"ModX");
  fHMviewX    =  new TH1F(buff,buff,10*(zend+20),-10,zend+10);
  fHMviewX    -> SetBit(kCanDelete);
  fHMviewX    -> SetMinimum(-2*ScintiWidth);
  fHMviewX    -> SetMaximum(ScintiWidth*(Nscinti+3));
  fHMviewX    -> Draw();
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

  //############### Y View ####################
  //###########################################
  fCMcanvas->cd();
  fPMviewY    -> cd();
  sprintf(buff,"ModY");
  fHMviewY    =  new TH1F(buff,buff,10*(zend+20),-10,zend+10);
  fHMviewY    -> SetBit(kCanDelete);
  fHMviewY    -> SetMinimum(-2*ScintiWidth);
  fHMviewY    -> SetMaximum(ScintiWidth*(Nscinti+3));
  fHMviewY    -> Draw();
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
  return;
}

Double_t moffset=0.;
void Draw_Hit(vector<Hit> &hitclster){
  fCMcanvas->cd();
  TMarker *fTMdepX;
  TMarker *fTMdepY;

  for(Int_t i=0; i<hitclster.size(); i++){
    //############## X View ##################
    //########################################
    if(hitclster[i].view==0){
      fPMviewX->cd();
      double x, z;
      if(hitclster[i].pln<=10){
	if(fINGRID_Dimension->get_posXY(0
					, XLyr
					, hitclster[i].pln
					, hitclster[i].ch
					, &x, &z)){
	  Double_t fSize = msize*hitclster[i].pe;
	  if(fSize>1)fSize=1;
	  fSize=1;//Debug
	  fTMdepX = new TMarker(z+moffset*PlnThick ,x+moffset*ScintiWidth ,20);
	  fTMdepX->SetBit(kCanDelete);
	  fTMdepX->SetMarkerColor(2);
	  fTMdepX->SetMarkerSize(fSize);
	  fTMdepX->Draw();
	  //LPrinti(hitclster,i);
	}
      }

      else if(hitclster[i].pln==13||hitclster[i].pln==14){
	if(fINGRID_Dimension->get_posVeto(0
					  , XLyr
					  , hitclster[i].pln
					  , hitclster[i].ch
					  , &x, &z)){
	  Double_t fSize = msize*hitclster[i].pe;
	  if(fSize>1)fSize=1;
	  fSize=1;//Debug
	  fTMdepX = new TMarker(z+moffset*ScintiWidth ,x+moffset ,20);
	  fTMdepX->SetBit(kCanDelete);
	  fTMdepX->SetMarkerColor(2);
	  fTMdepX->SetMarkerSize(fSize);
	  fTMdepX->Draw();
	}
      }


    }
    //############## Y View ##################
    //########################################
    else if(hitclster[i].view==1){
      fPMviewY->cd();
      double y, z;
      if(hitclster[i].pln<=10){
	if(fINGRID_Dimension->get_posXY(0
					, YLyr
					, hitclster[i].pln
					, hitclster[i].ch
					, &y, &z)){
	  Double_t fSize = msize*hitclster[i].pe;
	  if(fSize>1)fSize=1;
	  fSize=1;//Debug
	  fTMdepY = new TMarker(z+moffset*PlnThick ,y+moffset*ScintiWidth ,20);
	  fTMdepY->SetBit(kCanDelete);
	  fTMdepY->SetMarkerColor(2);
	  fTMdepY->SetMarkerSize(fSize);
	  fTMdepY->Draw();
	}
      }
      else if(hitclster[i].pln==11||hitclster[i].pln==12){
	if(fINGRID_Dimension->get_posVeto(0
					  , YLyr
					  , hitclster[i].pln
					  , hitclster[i].ch
					  , &y, &z)){
	  Double_t fSize = msize*hitclster[i].pe;
	  if(fSize>1)fSize=1;
	  fSize=1;//Debug
	  fTMdepY = new TMarker(z+moffset*ScintiWidth ,y+moffset ,20);
	  fTMdepY->SetBit(kCanDelete);
	  fTMdepY->SetMarkerColor(2);
	  fTMdepY->SetMarkerSize(fSize);
	  fTMdepY->Draw();
	}
      }
      

    }
  }
  fCMcanvas->Update();
}

//_______________________________________________________
Bool_t  DRAW = false;
TGraph* TGtrackx;
TGraph* TGtracky;
TF1*    pol1x;
TF1*    pol1y;
class pos{
public:
  double posxy;
  double  posz;
};

bool withposz(const pos& left, const pos& right){
  return left.posz < right.posz;
};
bool fSortposz(vector<pos> &a){
  std::stable_sort(a.begin(), a.end(), withposz);
};

bool LinFit(vector<Hit> &hitclster, 
	    float *ax, float *bx, 
	    float *ay, float *by){
  vector<pos>     xv,yv;
  double tempxy, tempz;
  pos temppos;
  for(Int_t i=0; i<hitclster.size(); i++){
    //##### X Layer ###########################
    //############# ###########################
    if(hitclster[i].view==0){
      if(hitclster[i].pln<=10){//Trackin plane
	if(fINGRID_Dimension->get_posXY(0 ,
					XLyr ,
					hitclster[i].pln ,
					hitclster[i].ch ,
					&tempxy , 
					&tempz
					)
	   )
	  {
	    temppos.posxy = tempxy;
	    temppos.posz = tempz;
	    xv.push_back(temppos);
	  }
      }//TPL
      if(hitclster[i].pln==13||hitclster[i].pln==14){//VETO plane
	if(fINGRID_Dimension->get_posVeto(0 ,
					XLyr ,
					hitclster[i].pln ,
					hitclster[i].ch ,
					&tempxy , 
					&tempz
					)
	   )
	  {
	    temppos.posxy = tempxy;
	    temppos.posz = tempz;
	    xv.push_back(temppos);
	  }
      }//Veto
    }//X
    //##### Y Layer ###########################
    //############# ###########################
    if(hitclster[i].view==1){
      if(hitclster[i].pln<=10){//Trackin plane
	if(fINGRID_Dimension->get_posXY(0 ,
					YLyr ,
					hitclster[i].pln ,
					hitclster[i].ch ,
					&tempxy , 
					&tempz
					)
	   )
	  {
	    temppos.posxy = tempxy;
	    temppos.posz = tempz;
	    yv.push_back(temppos);
	  }
      }//TPL
      if(hitclster[i].pln==11||hitclster[i].pln==12){//VETO plane
	if(fINGRID_Dimension->get_posVeto(0 ,
					YLyr ,
					hitclster[i].pln ,
					hitclster[i].ch ,
					&tempxy , 
					&tempz
					)
	   )
	  {
	    temppos.posxy = tempxy;
	    temppos.posz = tempz;
	    yv.push_back(temppos);
	  }
      }//Veto
    }//Y
  }//hit loop


  //#######  Fit X Layer #######################
  //############################################
  fSortposz(xv);
  Int_t    nhitx = xv.size();
  Double_t     x[nhitx];
  Double_t    zx[nhitx];
  for(int i = 0 ; i < nhitx ; i++){
    x [i] = xv[i].posxy;
    zx[i] = xv[i].posz;
  }

  TGtrackx  =  new TGraph(nhitx, zx, x);
  if(DRAW){
    fCMcanvas -> cd();
    fPMviewX  -> cd();
    TGtrackx  -> Draw("same");
    pol1x     -> Draw("same");
    fCMcanvas -> Update();
  }

  pol1x     =  new    TF1("pol1x","pol1",-10,150);
  TGtrackx  -> Fit("pol1x","qn","",-10,150);
  Double_t    chi2x   = pol1x -> GetChisquare();
  Double_t    ndfx    = pol1x -> GetNDF();
  Double_t    chindfx = chi2x/ndfx;

  //#######  Fit X Layer #######################
  //############################################
  fSortposz(yv);
  Int_t    nhity = yv.size();
  Double_t     y[nhity];
  Double_t    zy[nhity];
  for(int i = 0 ; i < nhity ; i++){
    y [i] = yv[i].posxy;
    zy[i] = yv[i].posz;
  }
  TGtracky  =  new TGraph(nhity, zy, y);
  if(DRAW){
    fCMcanvas -> cd();
    fPMviewY  -> cd();
    TGtracky  -> Draw("same");
    pol1y     -> Draw("same");
    fCMcanvas -> Update();
  }
  pol1y     =  new    TF1("pol1y","pol1",-10,150);
  TGtracky  -> Fit("pol1y","qn","",-10,150);
  Double_t    chi2y   = pol1y -> GetChisquare();
  Double_t    ndfy    = pol1y -> GetNDF();
  Double_t    chindfy = chi2y/ndfy;
  //####### Clear and delete function ###########


  if(chindfx < 10 && chindfy < 10 ){
    *ax = pol1x -> GetParameter(1);
    *bx = pol1x -> GetParameter(0);
    *ay = pol1y -> GetParameter(1);
    *by = pol1y -> GetParameter(0);

    pol1x    -> Clear();
    pol1y    -> Clear();
    TGtrackx -> Clear();
    TGtracky -> Clear();
    delete     pol1x;
    delete     pol1y;
    delete  TGtrackx;
    delete  TGtracky;
    
    return true;
  }
  else{
    pol1x    -> Clear();
    pol1y    -> Clear();
    TGtrackx -> Clear();
    TGtracky -> Clear();
    delete     pol1x;
    delete     pol1y;
    delete  TGtrackx;
    delete  TGtracky;

    return false;
  }
}
//_______________________________________________________


TCanvas *fChoughX;
TCanvas *fChoughY;
TH2F    *fH2houghX;
TH2F    *fH2houghY;
TF1     *h[20];
void HoughTrans(vector<Hit> &hitclster){
  fChoughY    = new TCanvas("houghY","houghY",500,400,700,600);
  fChoughX    = new TCanvas("houghX","houghX",500,200,700,400);
  char buff1[300],buff2[300];
  fH2houghX = new TH2F("fH2houghX","fH2houghX",100,0.,3.14,400,-200,200);
  fH2houghY = new TH2F("fH2houghY","fH2houghY",100,0.,3.14,400,-200,200);
  int countx=0;
  for(Int_t i=0; i<hitclster.size(); i++){

    //############## X View ##################
    //########################################
    if(hitclster[i].view==0){
      double x,z;
      if(fINGRID_Dimension->get_posXY(0
				      , XLyr
				      , hitclster[i].pln
				      , hitclster[i].ch
				      , &x, &z)){
	double theta = TMath::ATan(1.0*z/x);
	double ro    = sqrt(z*z+x*x);
	fH2houghX   -> Fill(theta, ro);
	fChoughX ->cd();
	sprintf(buff1,"X%02d",countx);
	sprintf(buff2,"%lf*TMath::Sin(%lf+x)",ro,theta);
	h[countx] =new TF1(buff1,buff2,0.,3.14);
	
	for(Int_t i=0;i<628;i++){
	  double th = 0.005*i;
	  fH2houghX->Fill(th, ro*TMath::Sin(theta+th));
	}
	/*
	if(countx==0){
	  h[countx]->Draw();
	}
	else if(countx>0){
	  h[countx]->Draw("same");
	}
	fChoughX->Update();
	*/
	countx++;
      }
    }

    if(hitclster[i].view==1){
      double y,z;
      if(fINGRID_Dimension->get_posXY(0
				      , YLyr
				      , hitclster[i].pln
				      , hitclster[i].ch
				      , &y, &z)){

	double theta = TMath::ATan(1.0*y/z);
	double ro    = sqrt(z*z+y*y);
	fH2houghY   -> Fill (theta, ro);
      }
    }
  }
  Int_t binx,biny,binz;
  fH2houghX->GetMaximumBin(binx,biny,binz);
  cout<<binx<<" "<<biny<<endl;
  Double_t mx =  0.+ (1.0*binx)*(3.14/100);
  Double_t my = -200.0 + (1.0*biny);
  cout<<mx<<" "<<my<<endl;
  Double_t a = -1./TMath::Tan(mx);
  Double_t b = 1.0*my/TMath::Sin(mx);
  cout<<a<<" "<<b<<endl;
  sprintf(buff1,"%lf*x+%lf",a,b);
  cout<<buff1<<endl;
  TF1 *f = new TF1(buff1,buff1,0,120);
  fCMcanvas->cd();
  fPMviewX->cd();
  f->SetLineColor(2);
  f->SetLineWidth(2);
  f->Draw("same");
  fCMcanvas->Update();

  fChoughX ->cd();
  fH2houghX->Draw("box");
  fChoughX ->Update();
  fChoughY ->cd();
  //fH2houghY->Draw("box");
  fChoughY ->Update();

}

#endif