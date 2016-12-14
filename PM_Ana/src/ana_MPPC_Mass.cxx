#ifndef _ANA_MPPC_C
#define _ANA_MPPC_C

#include<iostream>
#include<sstream>
#include<fstream>
using namespace std;
#include <iomanip.h>
#include <sys/stat.h>

#include <TROOT.h>
#include <TStyle.h>
#include <TApplication.h>
#include <TFile.h>
#include <TTree.h>
#include <TEventList.h>
#include <TBranch.h>
#include <TH1.h>
#include <TSystem.h>
#include <TGraph.h>
#include <TGaxis.h>
#include <TMarker.h>
#include <TText.h>
#include <TSpectrum.h>
#include <TF1.h>
#include <TMath.h>
#include <TSpectrum.h>
#include "TApplication.h"

#include "ana_MPPC_Mass.hxx"
ana_MPPC::ana_MPPC(){
  without_sigma=2.5;
}


/*
void ana_MPPC::analysis_old_version(TH1F *noise_hist){
  TF1 *gaus = new TF1("gaus","gaus",HIST_MIN,HIST_MAX);
  TF1 *dgaus = new TF1("dgaus","gaus(0)+gaus(3)",HIST_MIN,HIST_MAX);
  TSpectrum *peak1 = new TSpectrum();
  Double_t par[6];

  peak1->Search(noise_hist,2,"",0.1);
  pedestal_peak_pos = *(peak1->GetPositionX());
  onepe_peak_pos = *(peak1->GetPositionX()+1);
  if(pedestal_peak_pos>onepe_peak_pos){
    Double_t aaa = pedestal_peak_pos;
    pedestal_peak_pos = onepe_peak_pos;
    onepe_peak_pos=aaa;
  }
  gaus->SetParLimits(0,0,100000000);
  gaus->SetParLimits(1,0,300);
  gaus->SetParLimits(2,0,10);
  noise_hist->Fit("gaus","q","",(pedestal_peak_pos-FITRANGE),(pedestal_peak_pos+FITRANGE));
  gaus->GetParameters(par);
  gaus->SetParLimits(0,0,100000000);
  gaus->SetParLimits(1,0,300);
  gaus->SetParLimits(2,0,10);
  noise_hist->Fit("gaus","q","",(onepe_peak_pos-FITRANGE),(onepe_peak_pos+FITRANGE));
  gaus->GetParameters(par+3);
  dgaus->SetParameters(par);
  noise_hist->Fit("dgaus","q","",(pedestal_peak_pos-FITRANGE),(onepe_peak_pos+FITRANGE));
  pedestal_peak_pos = dgaus->GetParameter(1);
  pedestal_peak_height = dgaus->GetParameter(0);
  pedestal_peak_sigma = dgaus->GetParameter(2);
  onepe_peak_pos = dgaus->GetParameter(4);
  onepe_peak_height = dgaus->GetParameter(3);
  onepe_peak_sigma = dgaus->GetParameter(5);
  if(pedestal_peak_pos>onepe_peak_pos){
    Double_t aaa = pedestal_peak_pos;
    pedestal_peak_pos = onepe_peak_pos;
    onepe_peak_pos=aaa;
  }
  fChisquare=dgaus->GetChisquare();
  fNDF=dgaus->GetNDF();

  gain = onepe_peak_pos - pedestal_peak_pos;
}
*/
Bool_t ana_MPPC::analysis_old_version(TH1F *noise_hist){
  TF1 *gaus = new TF1("gaus","gaus",HIST_MIN,HIST_MAX);
  TF1 *dgaus = new TF1("dgaus","gaus(0)+gaus(3)",HIST_MIN,HIST_MAX);
  TSpectrum *peak1 = new TSpectrum();
  Double_t par[6];
  Int_t numpeak=2;
  //peak1->Search(noise_hist,2,"goff",0.1);
  peak1->Search(noise_hist,3,"goff",0.05); //for evaluate Mass test

  peak1->Search(noise_hist,2,"goff",0.1);
  if(peak1->GetNPeaks()<2){
    peak1->Search(noise_hist,3,"goff",0.1);
    if(peak1->GetNPeaks()<2){
      peak1->Search(noise_hist,2,"goff",0.05);
    }
  }


  pedestal_peak_pos = *(peak1->GetPositionX());
  onepe_peak_pos = *(peak1->GetPositionX()+1);
  if(pedestal_peak_pos>onepe_peak_pos){
    Double_t aaa = pedestal_peak_pos;
    pedestal_peak_pos = onepe_peak_pos;
    onepe_peak_pos=aaa;
  }

  /*
  gaus->SetParLimits(0,0,100000000);
  //gaus->SetParLimits(1,0,300);
  //gaus->SetParLimits(2,0,10);
  noise_hist->Fit("gaus","qn","",(pedestal_peak_pos-FITRANGE),(pedestal_peak_pos+FITRANGE));
  gaus->GetParameters(par);
  gaus->SetParLimits(0,0,100000000);
  //gaus->SetParLimits(1,0,300);
  //gaus->SetParLimits(2,0,10);
  noise_hist->Fit("gaus","qn","",(onepe_peak_pos-FITRANGE),(onepe_peak_pos+FITRANGE));
  gaus->GetParameters(par+3);
  dgaus->SetParameters(par);
  dgaus->SetParLimits(0,0,100000000);
  dgaus->SetParLimits(1,2500,2700);
  //dgaus->SetParLimits(2,0,10);
  dgaus->SetParLimits(3,0,100000000);
  dgaus->SetParLimits(4,2500,2700);
  //dgaus->SetParLimits(5,0,10);
  */

  dgaus -> SetParameters(400, pedestal_peak_pos, 2.0, 200, onepe_peak_pos, 2.0);
  noise_hist->Fit("dgaus","qn","",(pedestal_peak_pos-FITRANGEm),(onepe_peak_pos+FITRANGEp));
  dgaus ->GetParameters(par);
  noise_hist->Fit("dgaus","qn","",
		  (par[1]-1.5*par[2]),
		  (par[4]+1.5*par[5]));

  //pedestal_peak_pos   = dgaus->GetParameter(1);
  //pedestal_peak_sigma = dgaus->GetParameter(2);
  //onepe_peak_pos      = dgaus->GetParameter(4);
  //onepe_peak_sigma    = dgaus->GetParameter(5);
  
  //noise_hist->Fit("dgaus","","",
  //(pedestal_peak_pos-1.5*pedestal_peak_sigma),
  //	  (onepe_peak_pos   +1.5*onepe_peak_sigma));
  dgaus -> GetParameters(par);
  //pedestal_peak_pos    = dgaus->GetParameter(1);
  //pedestal_peak_height = dgaus->GetParameter(0);
  //pedestal_peak_sigma  = dgaus->GetParameter(2);
  //onepe_peak_pos       = dgaus->GetParameter(4);
  //onepe_peak_height    = dgaus->GetParameter(3);
  //onepe_peak_sigma     = dgaus->GetParameter(5);
  pedestal_peak_pos    = par[1];
  pedestal_peak_height = par[0];
  pedestal_peak_sigma  = par[2];
  onepe_peak_pos       = par[4];
  onepe_peak_height    = par[3];
  onepe_peak_sigma     = par[5];
  fChisquare           = dgaus->GetChisquare();
  fNDF                 = dgaus->GetNDF();
  gain = onepe_peak_pos - pedestal_peak_pos;

  //gaus->SetParameters(pedestal_peak_height,pedestal_peak_pos,pedestal_peak_sigma);
  gaus->SetParameters(par[0], par[1], par[2]);
  //number_of_pedestal_events = gaus->Integral(pedestal_peak_pos-4.5*pedestal_peak_sigma,pedestal_peak_pos+4.5*pedestal_peak_sigma);
  number_of_pedestal_events = gaus->Integral(par[1]-4.0*par[2],par[1]+4.0*par[2]);
  gaus->SetParameters(onepe_peak_height,onepe_peak_pos,onepe_peak_sigma);
  number_of_onepe_events = gaus->Integral(onepe_peak_pos-4.5*onepe_peak_sigma,onepe_peak_pos+4.5*onepe_peak_sigma);


  gaus  -> Clear();
  dgaus -> Clear();
  peak1 -> Clear();
  delete gaus;
  delete dgaus;
  delete peak1;

  if(pedestal_peak_height<onepe_peak_height){
    return false;
  }
  if(pedestal_peak_sigma>10||onepe_peak_sigma>10){
    return false;
  }
  //if(fChisquare/fNDF>15){
  //return false;
  //}

  return true;
}

void ana_MPPC::analysis_no_mppc(TH1F *pedestal_hist){
  TF1 *gaus = new TF1("gaus","gaus",HIST_MIN,HIST_MAX);
  TSpectrum *peak1 = new TSpectrum();
  Double_t par[3];
  peak1->Search(pedestal_hist,4,"goff",0.05);
  pedestal_peak_pos = *(peak1->GetPositionX());
  //debug peak serch
  if(pedestal_peak_pos>MAXPEDESTAL||pedestal_peak_pos<MINPEDESTAL||onepe_peak_pos<MINONEPE||onepe_peak_pos>MAXONEPE){
    peak1->Search(pedestal_hist,3,"goff",0.05);
    pedestal_peak_pos = *(peak1->GetPositionX());
    onepe_peak_pos = *(peak1->GetPositionX()+1);
  }
  pedestal_hist->Fit("gaus","qn","",(pedestal_peak_pos-FITRANGE*2),(pedestal_peak_pos+FITRANGE*2));
  gaus->GetParameters(par);
  pedestal_peak_pos = gaus->GetParameter(1);
  pedestal_peak_height = gaus->GetParameter(0);
  pedestal_peak_sigma = gaus->GetParameter(2);
  onepe_peak_pos = 0;
  onepe_peak_height = 0;
  onepe_peak_sigma = 0;
  gain=0;
}



Double_t ana_MPPC::get_gain(){
  return gain;
}
Double_t ana_MPPC::get_pedestal(){
  return pedestal_peak_pos;
}
Double_t ana_MPPC::get_pedestal_sigma(){
  return pedestal_peak_sigma;
}
Double_t ana_MPPC::get_pedestal_height(){
  return pedestal_peak_height;
}
Double_t ana_MPPC::get_onepe(){
  return onepe_peak_pos;
}

Double_t ana_MPPC::get_noise(Int_t entry){
  if(number_of_pedestal_events<10||number_of_pedestal_events>entry)return -444;
  noise= 1.0*log(1.0*entry/number_of_pedestal_events)/GATE*1000;
  mean_pe = 1.0*log(1.0*entry/number_of_pedestal_events);
  return noise;
}

Double_t ana_MPPC::get_crosstalk_and_afterpulse(Int_t entry){
  if(number_of_pedestal_events<10||number_of_pedestal_events>entry)return -444;
  crosstalk_and_afterpulse= 1.0-number_of_onepe_events/(number_of_pedestal_events*log(1.0*entry/number_of_pedestal_events));
  return crosstalk_and_afterpulse;
}

Double_t ana_MPPC::get_mean_pe(){
  return mean_pe;
}

//version 2009/04/20
//refined 2009/05/22
//refuse analysis() 2009/06/01
/*
void ana_MPPC::analysis(TH1F *pedestal_hist){
  noise_hist->Add(pedestal_hist);
  this->analysis();
}
*/
Bool_t ana_MPPC::analysis(TH1F *noise_hist){
  TF1 *gaus = new TF1("gaus","gaus",HIST_MIN,HIST_MAX);
  TF1 *dgaus = new TF1("dgaus","gaus(0)+gaus(3)",HIST_MIN,HIST_MAX);
  Double_t par[6];

  //get maximum bin X position
  fBinWidth=noise_hist->GetBinWidth(150);
  fBinMax=noise_hist->GetMaximumBin();
  fBinEdge=noise_hist->GetBinLowEdge(1);
  fXMax=fBinEdge+fBinWidth*fBinMax;
  pedestal_peak_pos=fXMax;//define maximum X position as pedestal peak

  //fit around pedestal_peak_pos and get sigma and peak number
  gaus->SetParLimits(0,0,100000000);
  gaus->SetParLimits(1,0,300);
  gaus->SetParLimits(2,0,10);
  noise_hist->Fit("gaus","qn","",(pedestal_peak_pos-FITRANGE),(pedestal_peak_pos+FITRANGE));
  pedestal_peak_pos = gaus->GetParameter(1);
  pedestal_peak_height = gaus->GetParameter(0);
  pedestal_peak_sigma = gaus->GetParameter(2);
  gaus->GetParameters(par);

  //define new histgram without pedestal peak
  Int_t fMinX_noise_hist_wo_pedestal=static_cast<Int_t>(pedestal_peak_pos+pedestal_peak_sigma*without_sigma);
 
  TH1F *noise_hist_wo_pedestal; 
  noise_hist_wo_pedestal = new TH1F("noise_hist_wo_pedestal","noise_hist_wo_pedestal",HIST_MAX-fMinX_noise_hist_wo_pedestal,fMinX_noise_hist_wo_pedestal,HIST_MAX);

  for(Int_t bin=0;bin<HIST_MAX-fMinX_noise_hist_wo_pedestal;bin++){
    Int_t ftempbincontent=noise_hist->GetBinContent(bin+fMinX_noise_hist_wo_pedestal-HIST_MIN);
    for(Int_t nevent=0;nevent<ftempbincontent;nevent++){
      noise_hist_wo_pedestal->Fill(fMinX_noise_hist_wo_pedestal+bin-1);
    }
  }

  //get maximum bin X position 
  fBinWidth=noise_hist_wo_pedestal->GetBinWidth(HIST_MAX-1);
  fBinMax=noise_hist_wo_pedestal->GetMaximumBin();
  fBinEdge=noise_hist_wo_pedestal->GetBinLowEdge(1);
  fXMax=fBinEdge+fBinWidth*fBinMax;
  onepe_peak_pos=fXMax;//define maximum X position as onepe peak
  gaus->SetParLimits(0,0,100000000);
  gaus->SetParLimits(1,0,300);
  gaus->SetParLimits(2,0,10);
  noise_hist_wo_pedestal->Fit("gaus","qn","",(onepe_peak_pos-FITRANGE),(onepe_peak_pos+FITRANGE));
  onepe_peak_pos = gaus->GetParameter(1);
  onepe_peak_height = gaus->GetParameter(0);
  onepe_peak_sigma = gaus->GetParameter(2);
  gaus->GetParameters(par+3);

  if(onepe_peak_sigma<0||onepe_peak_height<0)return false;
  //gaus->GetParameters(par+3);
  //fit by double gaussiun
  dgaus->SetParameters(par);

  ///////////////
  /*
  dgaus->SetParLimits(0,0,10000000);
  dgaus->SetParLimits(2,0,50);
  dgaus->SetParLimits(3,0,10000000);
  dgaus->SetParLimits(4,pedestal_peak_pos+3,pedestal_peak_pos+50);
  dgaus->SetParLimits(5,0,50);
  */
  ///////////////

  noise_hist->Fit("dgaus","qn","",(pedestal_peak_pos-FITRANGE),(onepe_peak_pos+FITRANGE));
  pedestal_peak_pos = dgaus->GetParameter(1);
  pedestal_peak_height = dgaus->GetParameter(0);
  pedestal_peak_sigma = dgaus->GetParameter(2);
  onepe_peak_pos = dgaus->GetParameter(4);
  onepe_peak_height = dgaus->GetParameter(3);
  onepe_peak_sigma = dgaus->GetParameter(5);
  fChisquare=dgaus->GetChisquare();
  fNDF=dgaus->GetNDF();
  gain=onepe_peak_pos-pedestal_peak_pos;
  delete noise_hist_wo_pedestal,gaus,dgaus;


  if(pedestal_peak_height<onepe_peak_pos){
    return false;
  }

  return true;
}

Bool_t ana_MPPC::set_gain_and_pedestal(Int_t temp,Int_t MPPC_HV,Int_t nmod,Int_t ntfb,Int_t nch){
  char buff1[300];
  sprintf(buff1,"%s/gain_and_pedestal_temp_%d_HV_%d.txt",gain_and_pedestal_folder,temp,MPPC_HV);
  struct stat st;
  if ((stat(buff1,&st))!=0){
    std::cerr << "Cannot find file: " << buff1 << std::endl;
    return false;
  }
  ifstream gain_and_pedestal(buff1);
  Double_t temp3,temp1,temp2;
  for(Int_t nummod=0;nummod<NumMod;nummod++){
    for(Int_t numtfb=0;numtfb<NumTFB;numtfb++){
      for(Int_t numch=0;numch<NumCh;numch++){
	gain_and_pedestal>>temp3>>temp3>>temp3>>temp1>>temp3>>temp2;
	if(nummod==nmod&&numtfb==ntfb&&numch==nch){
	  gain=temp2;
	  pedestal_peak_pos=temp1;
	  return true;
	}//if
      }//numch
    }//numtfb
  }//nummod
}

Bool_t ana_MPPC::set_gain_and_pedestal(Int_t run_number,Int_t nmod,Int_t ntfb,Int_t nch){
  char buff1[300];
  sprintf(buff1,"%s/ingrid_%08d_0000.daq.mid.gap.txt",gain_and_pedestal_folder,run_number);
  struct stat st;
  if ((stat(buff1,&st))!=0){
    std::cerr << "Cannot find file: " << buff1 << std::endl;
    return false;
  }
  ifstream gain_and_pedestal(buff1);
  Double_t temp3,temp1,temp2;
  for(Int_t nummod=0;nummod<NumMod;nummod++){
    for(Int_t numtfb=0;numtfb<NumTFB;numtfb++){
      for(Int_t numch=0;numch<NumCh;numch++){
	gain_and_pedestal>>temp3>>temp3>>temp3>>temp1>>temp3>>temp2;
	if(nummod==nmod&&numtfb==ntfb&&numch==nch){
	  gain=temp2;
	  pedestal_peak_pos=temp1;
	  return true;
	}//if
      }//numch
    }//numtfb
  }//nummod
}

#endif
