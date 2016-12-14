//#check if error value for xsec is really -3,-2,-1,0,1,2,3
#include<iostream>
#include<sstream>
#include<fstream>
using namespace std;
#include <iomanip>
//#include <pair>
#include <sys/stat.h>
#include <cmath>
#include <TMinuit.h>
#include <TFitter.h>
#include <TROOT.h>
#include <TStyle.h>
#include <TApplication.h>
#include <TFile.h>
#include <TCanvas.h>
#include <TTree.h>
#include <TClonesArray.h>
#include <TObject.h>
#include <TEventList.h>
#include <TBranch.h>
#include <TH1.h>
#include <TH2.h>
#include <TH3.h>
#include <TProfile.h>
#include <TFrame.h>
#include <TRandom3.h>
#include <TChain.h>
#include <TLegend.h>
#include <TF1.h>
#include <TGraph.h>
#include <TGaxis.h>
#include <TMarker.h>
#include <TText.h>
#include <TMath.h>
#include <TSpectrum.h>
#include <TMatrixD.h>
#include <TVectorD.h>
#include <TGraphErrors.h>
#include <TBox.h>
#include <TLatex.h>
#include <TString.h>
#include <TSystem.h>
#include <THStack.h>
#include <TBox.h>
#include "setup.h"
#include "Reconstruction.cc"
#include "Xsec.cc"
//#define DEBUG

int main(int argc, char ** argv){

  //TApplication theApp("App",0,0);
  gStyle->SetOptFit(kTRUE);
  Xsec * XS = new Xsec();
  XS->Xsec::Initialize();
  char * OutputName = new char[256];
  bool UnfoldedPlots=false;
  const int NBinsMom=NBinsTrueMom;
  const int NBinsAngle=NBinsTrueAngle;
  
  int c=-1;
  while ((c = getopt(argc, argv, "uo:")) != -1) {
    switch(c){
    case 'u':
      UnfoldedPlots=true;
      break;
    case 'o':
      OutputName=optarg;
      break;      
    }
  }

  if(UnfoldedPlots){
    const int NBinsMom=NBinsTrueMom;
    const int NBinsAngle=NBinsTrueAngle;
  }

  cout<<"CAREFUL: TO UNDERSTAND -> When XS error is varied, XS of 0 is different from the nominal MC that I have!!!!"<<endl; 
  char * txtDataName = new char[256];
  char * txtMCName = new char[256];
  double DataReconstructedEvents[NBinsMom][NBinsAngle];
  double MCReconstructedEvents[NBinsMom][NBinsAngle];
  //double Covariance[EndError+1][EndError+1][NBinsMom][NBinsAngle][NBinsMom][NBinsAngle];
  //double Correlation[EndError+1][EndError+1][NBinsMom][NBinsAngle][NBinsMom][NBinsAngle];//
  double CovarianceReduced[EndError+1][NBinsMom][NBinsAngle][NBinsMom][NBinsAngle];
  double CorrelationReduced[EndError+1][NBinsMom][NBinsAngle][NBinsMom][NBinsAngle];

  double CovarianceFlux[NBinsMom][NBinsAngle][NBinsMom][NBinsAngle];
  double CorrelationFlux[NBinsMom][NBinsAngle][NBinsMom][NBinsAngle];
  double CovarianceXS[NBinsMom][NBinsAngle][NBinsMom][NBinsAngle];
  double CorrelationXS[NBinsMom][NBinsAngle][NBinsMom][NBinsAngle];
  for(int e0=0;e0<NBinsMom;e0++){//loop over effect 0
    for(int e1=0;e1<NBinsAngle;e1++){//loop over effect 1
      int bin1=NBinsAngle*e0+e1;
      for(int f0=0;f0<NBinsMom;f0++){//loop over effect 0
	for(int f1=0;f1<NBinsAngle;f1++){//loop over effect 1
	  int bin2=NBinsAngle*f0+f1;
	  CovarianceXS[e0][e1][f0][f1]=0;
	  CovarianceFlux[e0][e1][f0][f1]=0;
	}
      }
    }
  }
  //FOR DEBUG
  //bool Covariance1[(EndError+1)*(EndError+1)][NBinsMom*NBinsAngle][NBinsMom*NBinsAngle]={};//intialize with only zero
  //double Covariance[EndError+1][EndError+1][NBinsMom][NBinsAngle][NBinsMom][NBinsAngle];//intialize with only zero
  //bool Covariance1[EndError+1][EndError+1][NBinsMom*NBinsAngle][NBinsMom*NBinsAngle];
  //bool Covariance2[5*(EndError+1)][NBinsMom*NBinsAngle][NBinsMom*NBinsAngle];
  //cout<<EndError+1<<", "<<EndError+1<<", "<<NBinsMom*NBinsAngle<<", "<<NBinsMom*NBinsAngle<<endl;
  //  for(int s0=0;s0<=Systematics_Xsec_End-Systematics_Xsec_Start;s0++){
  //   for(int s1=0;s1<=Systematics_Xsec_End-Systematics_Xsec_Start;s1++){

  for(int s0=0;s0<=EndError;s0++){
    for(int s1=0;s1<=EndError;s1++){
      
      for(int e0=0;e0<NBinsMom;e0++){//loop over effect 0
	for(int e1=0;e1<NBinsAngle;e1++){//loop over effect 1
	  int bin1=NBinsAngle*e0+e1;
	  for(int f0=0;f0<NBinsMom;f0++){//loop over effect 0
	    for(int f1=0;f1<NBinsAngle;f1++){//loop over effect 1
	       int bin2=NBinsAngle*f0+f1;
	       //Covariance[s0][s1][e0][e1][f0][f1]=0;
	       //Correlation[s0][s1][e0][e1][f0][f1]=0;
	       CovarianceReduced[s0][e0][e1][f0][f1]=0;
	       CorrelationReduced[s0][e0][e1][f0][f1]=0;
	       //FOR DEBUG
	       //Covariance2[s0][bin1][bin2]=0;
	       //Covariance1[s0][s1][bin1][bin2]=0;
	       //cout<<Covariance[s0][s1][e0][e1][f0][f1]<<endl;
	    }
	  }
	}
      }
    }    
  }

    //FOR DEBUG
  /*
  for(int s0=0;s0<=EndError;s0++){
    for(int s1=0;s1<=EndError;s1++){
      for(int e0=0;e0<NBinsMom;e0++){//loop over effect 0
	for(int e1=0;e1<NBinsAngle;e1++){//loop over effect 1
	  int bin1=NBinsAngle*e0+e1;
	  for(int f0=0;f0<NBinsMom;f0++){//loop over effect 0
	    for(int f1=0;f1<NBinsAngle;f1++){//loop over effect 1
	       int bin2=NBinsAngle*f0+f1;
	       //cout<<s0<<", "<<s1<<", "<<bin1<<", "<<bin2<<", cova="<<CovarianceReduced[s0][e0][e1][f0][f1]<<endl; 
	       //cout<<Covariance1[s0][s1][bin1][bin2]<<endl;
		 //Covariance[s0][s1][e0][e1][f0][f1]=0;
	       //Correlation[s0][s1][e0][e1][f0][f1]=0;
	       //cout<<Covariance[s0][s1][e0][e1][f0][f1]<<endl;
	    }
	  }
	}
      }
    }
  }
  */

  
  TFile * file = new TFile(OutputName,"recreate");
  TDirectory * NoiseEventFunctions = file->mkdir("NoiseEventFunctions");
  TDirectory * HitEfficiencyFunctions = file->mkdir("HitEfficiencytFunctions");
  TDirectory * DataMCErrorFunctions = file->mkdir("DataMCErrorFunctions");
  TDirectory * FluxEventFunctions = file->mkdir("FluxEventFunctions");
  TDirectory * XSEventFunctions = file->mkdir("XSEventFunctions");

  //TH1D * NEvents[EndError+1][NBinsMom][NBinsAngle];
  TH2D * NominalMC = new TH2D("NominalMC","",NBinsMom,0,NBinsMom,NBinsAngle,0,NBinsAngle);
  TH2D * NominalMC_XSTemp = new TH2D("NominalMC_XSTemp","",NBinsMom,0,NBinsMom,NBinsAngle,0,NBinsAngle);
  TH2D * NominalData = new TH2D("NominalData","",NBinsMom,0,NBinsMom,NBinsAngle,0,NBinsAngle);

  TH2D * Error_Minus[EndError+1]; TH2D * Error_Plus[EndError+1];
  //For Noise error 
  TH1D * ErrorNoise[NBinsMom][NBinsAngle];
  TH1D * ErrorNoise_Norm[NBinsMom][NBinsAngle];
  TF1 * fErrorNoise[NBinsMom][NBinsAngle];

  //For Hit efficiency error
  TH1D * ErrorHitEfficiency[NBinsMom][NBinsAngle];
  TF1 * fErrorHitEfficiency[NBinsMom][NBinsAngle];

  //For flux error
  TH1D * ErrorFlux[NBinsMom][NBinsAngle];
  TF1 * fErrorFlux[NBinsMom][NBinsAngle];

  //For reconstruction error
  TH1D * MCContent[EndError+1][NBinsMom][NBinsAngle];
  TH1D * DataContent[EndError+1][NBinsMom][NBinsAngle];
 
 //For Xsection errors
  TH1D * ErrorXS[Systematics_Xsec_End-Systematics_Xsec_Start+1][NBinsMom][NBinsAngle];
  TH1D * ErrorXS_Norm[Systematics_Xsec_End-Systematics_Xsec_Start+1][NBinsMom][NBinsAngle];
  TSpline3 * sErrorXS[Systematics_Xsec_End-Systematics_Xsec_Start+1][NBinsMom][NBinsAngle];
  TGraph * gErrorXS[Systematics_Xsec_End-Systematics_Xsec_Start+1][NBinsMom][NBinsAngle];
  double xXS[Systematics_Xsec_End-Systematics_Xsec_Start+1][NBinsMom][NBinsAngle][NXsecVariations];
  double yXS[Systematics_Xsec_End-Systematics_Xsec_Start+1][NBinsMom][NBinsAngle][NXsecVariations];


  TH1D * NominalMC_RecMom = new TH1D("NominalMC_RecMom","",NBinsMom,0,NBinsMom);
  TH1D * NominalMC_RecAngle = new TH1D("NominalMC_RecAngle","",NBinsAngle,0,NBinsAngle);







  
  for(int ErrorType=StartError;ErrorType<=EndError;ErrorType++){
    //if(!(ErrorType==0 || ErrorType==2 || ErrorType==16 || ErrorType>=17 || (ErrorType>=4 && ErrorType<=7))) continue;//TEMP
    //if(!(ErrorType==0 || (ErrorType==3)  /*|| ErrorType==5*/)) continue;//TEMP
    if(!(ErrorType==0 || (ErrorType>=16))) continue;//TEMP
    //if(ErrorType==0) NE[0]=1;//TEMP
    cout<<"The error currently tested is number "<<ErrorType<<endl;


    
    //##############################HISTOGRAM INITIALIZATION#########################################
    Error_Minus[ErrorType] = new TH2D(Form("Error_Minus[%d]",ErrorType),"",NBinsMom,0,NBinsMom,NBinsAngle,0,NBinsAngle);
    Error_Plus[ErrorType] = new TH2D(Form("Error_Plus[%d]",ErrorType),"",NBinsMom,0,NBinsMom,NBinsAngle,0,NBinsAngle);
      
    for(int e0=0;e0<NBinsMom;e0++){//loop over effect 0
      for(int e1=0;e1<NBinsAngle;e1++){//loop over effect 1
	if(ErrorType==2){
	  ErrorNoise[e0][e1] = new TH1D(Form("ErrorNoise[%d][%d]",e0,e1),"",NE[2]+1,Start[2],End[2]);
	  ErrorNoise_Norm[e0][e1] = new TH1D(Form("ErrorNoise_Norm[%d][%d]",e0,e1),"",NE[2]+1,Start[2],End[2]);
	  fErrorNoise[e0][e1] = new TF1(Form("fErrorNoise[%d][%d]",e0,e1),"pol1",Start[2],End[2]);
	}
	else if(ErrorType==3){
	  // ErrorHitEfficiency[e0][e1] = new TH1D(Form("ErrorHitEfficiency[%d][%d]",e0,e1),"",NE[2]+1,Start[2],End[2]);
	  //	  fErrorHitEfficiency[e0][e1] = new TF1(Form("fErrorHitEfficiency[%d][%d]",e0,e1),"pol1",Start[2],End[2]);
	  ErrorHitEfficiency[e0][e1] = new TH1D(Form("ErrorHitEfficiency[%d][%d]",e0,e1),"",600,-3,3);
	  fErrorHitEfficiency[e0][e1] = new TF1(Form("fErrorHitEfficiency[%d][%d]",e0,e1),"pol1",-3,3);
	}
	else if(ErrorType>=7 && ErrorType<=Systematics_Detector_End){
	  MCContent[ErrorType][e0][e1] = new TH1D(Form("MCContent[%d][%d][%d]",ErrorType,e0,e1),"",NE[ErrorType]+1,Start[ErrorType],End[ErrorType]);
	  DataContent[ErrorType][e0][e1] = new TH1D(Form("DataContent[%d][%d][%d]",ErrorType,e0,e1),"",NE[ErrorType]+1,Start[ErrorType],End[ErrorType]);
	}
	else if(ErrorType==16){
	  ErrorFlux[e0][e1] = new TH1D(Form("ErrorFlux[%d][%d]",e0,e1),"",600,-3,3);
	  fErrorFlux[e0][e1] = new TF1(Form("fErrorFlux[%d][%d]",e0,e1),"gaus",-3,3);
	}
	else if(ErrorType>=Systematics_Xsec_Start && ErrorType<=Systematics_Xsec_End){
	  ErrorXS[ErrorType-Systematics_Xsec_Start][e0][e1] = new TH1D(Form("ErrorXS[%d][%d][%d]",ErrorType-Systematics_Xsec_Start,e0,e1),"",620,-3.1,3.1);
	  ErrorXS_Norm[ErrorType-Systematics_Xsec_Start][e0][e1] = new TH1D(Form("ErrorXS_Norm[%d][%d][%d]",ErrorType-Systematics_Xsec_Start,e0,e1),"",620,-3.1,3.1);
	  //sErrorXS[ErrorType-Systematics_Xsec_Start][e0][e1] = ?????new TF1(Form("fErrorFlux[%d][%d]",e0,e1),"gaus",-3,3);
	}
      }
    }
    //##############################END OF INITIALIZATION#########################################



    //#################################TEMPORARY, SINCE THE XS VARIATION OF 0 SIGMA DOES NOT CORRESPONDS TO THE NOMINAL MC, WE REDEFINE NOMINAL ONLY FOR XS ERROR AS THE 0 SIGMA VARIATION#################################
    if(ErrorType>=Systematics_Xsec_Start && ErrorType<=Systematics_Xsec_End){
      int n=3;
      double ErrorValue=Start[ErrorType]+n*Step[ErrorType];
      /*     
      if(UnfoldedPlots){
	sprintf(txtMCName,"/home/bquilain/CC0pi_XS/XS/files/MCUnfolded_Systematics%d_%d.root",ErrorType,n);
	XS->Xsec::LoadInputFiles_UnfoldedData(txtMCName,MCReconstructedEvents);
      }
      else{
	sprintf(txtMCName,"/home/bquilain/CC0pi_XS/XS/files/MCSelected_Systematics%d_%d.txt",ErrorType,n);
	XS->Xsec::LoadInputFiles_OnlySelectedData(txtMCName,MCReconstructedEvents);
      }
*/      
      sprintf(txtMCName,"/home/bquilain/CC0pi_XS/XS/files/MCUnfolded_Systematics%d_%d.root",ErrorType,n);
      XS->Xsec::LoadInputFiles_UnfoldedData(txtMCName,MCReconstructedEvents);

      for(int e0=0;e0<NBinsMom;e0++){//loop over effect 0
      for(int e1=0;e1<NBinsAngle;e1++){//loop over effect 1
      NominalMC_XSTemp->SetBinContent(e0,e1,MCReconstructedEvents[e0][e1]);
    }
    }
    }
      //#################################################################"

    
    
    

    //##############################FILL THE HISTOGRAMS#########################################
    for(int n=0;n<NE[ErrorType];n++){
      double ErrorValue=Start[ErrorType]+n*Step[ErrorType];
      sprintf(txtMCName,"/home/bquilain/CC0pi_XS/XS/files/MCUnfolded_Systematics%d_%d.root",ErrorType,n);

      if(ErrorType>=7 && ErrorType<=Systematics_Detector_End) sprintf(txtMCName,"/home/bquilain/CC0pi_XS/XS/files/DataSelected_Systematics%d_%d.txt",ErrorType,n);
      else sprintf(txtDataName,"/home/bquilain/CC0pi_XS/XS/files/MCSelected_Systematics0_0.txt");
      //cout<<"good"<<endl;
      XS->Xsec::LoadInputFiles_UnfoldedData(txtMCName,MCReconstructedEvents);
      for(int e0=0;e0<NBinsMom;e0++){//loop over effect 0
	cout<<"bin mom="<<e0<<endl;
	for(int e1=0;e1<NBinsAngle;e1++){//loop over effect 1
	  cout<<"ang="<<e1<<", "<<MCReconstructedEvents[e0][e1]<<endl;
	}
      }
      for(int e0=0;e0<NBinsMom;e0++){//loop over effect 0
	for(int e1=0;e1<NBinsAngle;e1++){//loop over effect 1
	  if(ErrorType==0){
	    NominalMC->SetBinContent(e0+1,e1+1,MCReconstructedEvents[e0][e1]);
	    NominalData->SetBinContent(e0+1,e1+1,DataReconstructedEvents[e0][e1]);
	    
	    //if(NominalMC->GetBinContent(e0,e1)!=0) cout<<"NominalMC="<<NominalMC->GetBinContent(e0,e1)<<endl;
	  }
	  double RelativeValue=MCReconstructedEvents[e0][e1]-NominalMC->GetBinContent(e0+1,e1+1);
	  if(NominalMC->GetBinContent(e0,e1)!=0) RelativeValue/=NominalMC->GetBinContent(e0+1,e1+1);
	  
	  if(ErrorType==2){
	    ErrorNoise[e0][e1]->Fill(ErrorValue,MCReconstructedEvents[e0][e1]);
	    ErrorNoise_Norm[e0][e1]->Fill(ErrorValue);
	    //cout<<e0<<","<<e1<<"="<<MCReconstructedEvents[e0][e1]<<endl;
	  }
	  else if(ErrorType==3){
	    Error_Minus[ErrorType]->SetBinContent(e0+1,e1+1,-TMath::Abs(RelativeValue));
	    Error_Plus[ErrorType]->SetBinContent(e0+1,e1+1,TMath::Abs(RelativeValue));

	    ErrorHitEfficiency[e0][e1]->Fill(RelativeValue);//FINALLY USELESS
	    for(int f0=0;f0<NBinsMom;f0++){//loop over effect 0
	      for(int f1=0;f1<NBinsAngle;f1++){//loop over effect 1
		//Covariance[ErrorType][ErrorType][e0][e1][f0][f1]+=(1./(NE[ErrorType]-1.))*(MCReconstructedEvents[e0][e1]-NominalMC->GetBinContent(e0,e1))*(MCReconstructedEvents[f0][f1]-Nominal);
		CovarianceReduced[ErrorType][e0][e1][f0][f1]+=(1./(NE[ErrorType]-1.))*(MCReconstructedEvents[e0][e1]-NominalMC->GetBinContent(e0,e1))*(MCReconstructedEvents[f0][f1]-Nominal);
	      }
	    }
	  }
	  else if(ErrorType==4){
	    //if(NominalMC->GetBinContent(e0,e1)!=0) cout<<"NominalMC="<<NominalMC->GetBinContent(e0,e1)<<", Varied="<<MCReconstructedEvents[e0][e1]<<endl;
	    Error_Minus[ErrorType]->SetBinContent(e0,e1,-TMath::Abs(RelativeValue));
	    Error_Plus[ErrorType]->SetBinContent(e0,e1,TMath::Abs(RelativeValue));
	    for(int f0=0;f0<NBinsMom;f0++){//loop over effect 0
	      for(int f1=0;f1<NBinsAngle;f1++){//loop over effect 1
		//Covariance[ErrorType][ErrorType][e0][e1][f0][f1]+=(1./(NE[ErrorType]-1.))*(MCReconstructedEvents[e0][e1]-NominalMC->GetBinContent(e0,e1))*(MCReconstructedEvents[f0][f1]-NominalMC->GetBinContent(f0,f1));
		CovarianceReduced[ErrorType][e0][e1][f0][f1]+=(1./(NE[ErrorType]-1.))*(MCReconstructedEvents[e0][e1]-NominalMC->GetBinContent(e0,e1))*(MCReconstructedEvents[f0][f1]-NominalMC->GetBinContent(f0,f1));
		
	      }
	    }	    
	  //NEvents[NBinsMom][NBinsAngle]->Fill(e0,e1,MCReconstructedEvents[e0][e1]);
	  }
	  else if(ErrorType==5){
	    if(MCReconstructedEvents[e0][e1]>=NominalMC->GetBinContent(e0,e1)){
	      if(NominalMC->GetBinContent(e0,e1)!=0) Error_Plus[ErrorType]->SetBinContent(e0,e1,RelativeValue);
	      Error_Plus[ErrorType]->SetBinContent(e0,e1,RelativeValue);
	    }
	    else Error_Minus[ErrorType]->SetBinContent(e0,e1,RelativeValue);

	    for(int f0=0;f0<NBinsMom;f0++){//loop over effect 0
	      for(int f1=0;f1<NBinsAngle;f1++){//loop over effect 1
		//Covariance[ErrorType][ErrorType][e0][e1][f0][f1]+=(1./(NE[ErrorType]-1.))*(MCReconstructedEvents[e0][e1]-NominalMC->GetBinContent(e0,e1))*(MCReconstructedEvents[f0][f1]-NominalMC->GetBinContent(f0,f1));
		CovarianceReduced[ErrorType][e0][e1][f0][f1]+=(1./(NE[ErrorType]-1.))*(MCReconstructedEvents[e0][e1]-NominalMC->GetBinContent(e0,e1))*(MCReconstructedEvents[f0][f1]-NominalMC->GetBinContent(f0,f1));
	      }
	    }	    
	    //cout<<"Birks attenuation length error is changed"
	    //NEvents[NBinsMom][NBinsAngle]->Fill(e0,e1,MCReconstructedEvents[e0][e1]);
	  }
	  else if(ErrorType==6){
	    if(MCReconstructedEvents[e0][e1]>=NominalMC->GetBinContent(e0,e1)) Error_Plus[ErrorType]->SetBinContent(e0,e1,RelativeValue);
	    else Error_Minus[ErrorType]->SetBinContent(e0,e1,RelativeValue);
	    for(int f0=0;f0<NBinsMom;f0++){//loop over effect 0
	      for(int f1=0;f1<NBinsAngle;f1++){//loop over effect 1
		//Covariance[ErrorType][ErrorType][e0][e1][f0][f1]+=(1./(NE[ErrorType]-1.))*(MCReconstructedEvents[e0][e1]-NominalMC->GetBinContent(e0,e1))*(MCReconstructedEvents[f0][f1]-NominalMC->GetBinContent(f0,f1));
		CovarianceReduced[ErrorType][e0][e1][f0][f1]+=(1./(NE[ErrorType]-1.))*(MCReconstructedEvents[e0][e1]-NominalMC->GetBinContent(e0,e1))*(MCReconstructedEvents[f0][f1]-NominalMC->GetBinContent(f0,f1));
	      }
	    }	    
	  }
	  else if(ErrorType>=7 && ErrorType<=Systematics_Detector_End){
	    double RelativeMC=MCReconstructedEvents[e0][e1];
	    double RelativeData=DataReconstructedEvents[e0][e1];
	    if(NominalMC->GetBinContent(e0,e1)!=0) RelativeMC/=NominalMC->GetBinContent(e0,e1);
	    if(NominalData->GetBinContent(e0,e1)!=0) RelativeData/=NominalData->GetBinContent(e0,e1);
	    if(NominalMC->GetBinContent(e0,e1)!=0) cout<<"n="<<n<<", Relative MC="<<RelativeMC<<", Data="<<RelativeData<<endl;
	    //cout<<"Data="<<DataReconstructedEvents[e0][e1]<<", relative="<<RelativeData<<endl;
	    MCContent[ErrorType][e0][e1]->Fill(ErrorValue,RelativeMC);
	    DataContent[ErrorType][e0][e1]->Fill(ErrorValue,RelativeData);	    
	  }
	  else if(ErrorType==16){
	    //cout<<RelativeValue<<endl;
	    ErrorFlux[e0][e1]->Fill(RelativeValue);
	    //cout<<e0<<","<<e1<<"="<<MCReconstructedEvents[e0][e1]<<endl;
	    for(int f0=0;f0<NBinsMom;f0++){//loop over effect 0
	      for(int f1=0;f1<NBinsAngle;f1++){//loop over effect 1
		//Covariance[ErrorType][ErrorType][e0][e1][f0][f1]+=(1./(NE[ErrorType]-1.))*(MCReconstructedEvents[e0][e1]-NominalMC->GetBinContent(e0,e1))*(MCReconstructedEvents[f0][f1]-NominalMC->GetBinContent(f0,f1));
		//CovarianceReduced[ErrorType][e0][e1][f0][f1]+=(1./(NE[ErrorType]-1.))*(MCReconstructedEvents[e0][e1]-NominalMC->GetBinContent(e0,e1))*(MCReconstructedEvents[f0][f1]-NominalMC->GetBinContent(f0,f1));
		//cout<<MCReconstructedEvents[e0][e1]-NominalMC->GetBinContent(e0,e1)<<", "<<MCReconstructedEvents[f0][f1]-NominalMC->GetBinContent(f0,f1)<<endl;
		CovarianceFlux[e0][e1][f0][f1]+=(1./(NE[ErrorType]-1.))*(MCReconstructedEvents[e0][e1]-NominalMC->GetBinContent(e0,e1))*(MCReconstructedEvents[f0][f1]-NominalMC->GetBinContent(f0,f1));
	      }
	    }
	  }
	  else if(ErrorType>=Systematics_Xsec_Start && ErrorType<=Systematics_Xsec_End){
	    double XsecVariation=ErrorValue-(ErrorType-Systematics_Xsec_Start)*NXsecVariations-CenterXsecVariations;//The variation of Xsec parameter, in #sigma. A number between 0 and 175 - the center of the current systematic source (nominal). For example, for Xsec error source #10, it starts from 7*(10-1)=63 and ends at 70. from 63 to 70, it contains the variariation of -3,-2,-1,0,1,2,3 sigma respectively. The center is then located at 66. For the example of a 2 sigma variation, the substraction will be therefore equal to: 68-66=2, which gives the number of sigmas!
	    //if(XsecVariation==0) NominalMC_XSTemp->SetBinContent(e0,e1,MCReconstructedEvents[e0][e1]);

	    double RelativeMC=MCReconstructedEvents[e0][e1];
	    if(NominalMC_XSTemp->GetBinContent(e0,e1)!=0) RelativeMC/=NominalMC_XSTemp->GetBinContent(e0,e1);

	    ErrorXS[ErrorType-Systematics_Xsec_Start][e0][e1]->Fill(XsecVariation,RelativeMC);	    
	    ErrorXS_Norm[ErrorType-Systematics_Xsec_Start][e0][e1]->Fill(XsecVariation);
	    //cout<<XsecVariation<<endl;
	    xXS[ErrorType-Systematics_Xsec_Start][e0][e1][((int) (XsecVariation+CenterXsecVariations))]=XsecVariation;
	    yXS[ErrorType-Systematics_Xsec_Start][e0][e1][((int) (XsecVariation+CenterXsecVariations))]=RelativeMC;
	    

	    /*	    if(XsecVariation<-1){
	      if(e0==0 && e1==0) cout<<"Temp, keep only variation +-1 sigma in XS"<<endl;
	      yXS[ErrorType-Systematics_Xsec_Start][e0][e1][((int) (XsecVariation+CenterXsecVariations))]=1;//TEMP
	      }*/
	    
	  }
	}	  
      }
    }
    //cout<<"HERE="<<ErrorType<<endl;
    if(ErrorType==2){
      for(int e0=0;e0<NBinsMom;e0++){//loop over effect 0
	for(int e1=0;e1<NBinsAngle;e1++){//loop over effect 1
	  NoiseEventFunctions->cd();
  ErrorNoise[e0][e1]->Divide(ErrorNoise_Norm[e0][e1]);
	  ErrorNoise[e0][e1]->Fit(Form("fErrorNoise[%d][%d]",e0,e1),"RQ");
	  ErrorNoise[e0][e1]->Write();

	  double RelativeValue=fErrorNoise[e0][e1]->Eval(0)-NominalMC->GetBinContent(e0,e1);
	  if(NominalMC->GetBinContent(e0,e1)!=0) RelativeValue/=NominalMC->GetBinContent(e0,e1);

	  Error_Minus[ErrorType]->SetBinContent(e0,e1,-TMath::Abs(RelativeValue));
	  Error_Plus[ErrorType]->SetBinContent(e0,e1,TMath::Abs(RelativeValue));

	  for(int f0=0;f0<NBinsMom;f0++){//loop over effect 0
	    for(int f1=0;f1<NBinsAngle;f1++){//loop over effect 1
	      double RelativeValue2=fErrorNoise[f0][f1]->Eval(0)-NominalMC->GetBinContent(f0,f1);
	      if(NominalMC->GetBinContent(f0,f1)!=0) RelativeValue2/=NominalMC->GetBinContent(f0,f1);
	      //Covariance[ErrorType][ErrorType][e0][e1][f0][f1]+=(MCReconstructedEvents[e0][e1]*(1+RelativeValue)-NominalMC->GetBinContent(e0,e1))*(MCReconstructedEvents[f0][f1]*(1+RelativeValue2)-NominalMC->GetBinContent(f0,f1));
	      CovarianceReduced[ErrorType][e0][e1][f0][f1]+=(MCReconstructedEvents[e0][e1]*(1+RelativeValue)-NominalMC->GetBinContent(e0,e1))*(MCReconstructedEvents[f0][f1]*(1+RelativeValue2)-NominalMC->GetBinContent(f0,f1));
	    }
	  }	    

	  
	  //for(int nt=0;nt<NToys;nt++){
	    
	    //for(int f0=0;f0<NBinsMom;f0++){//loop over effect 0
	      //for(int f1=0;f1<NBinsAngle;f1++){//loop over effect 1
		//Covariance[ErrorType][ErrorType][e0][e1][f0][f1]+=(MCReconstructedEvents[e0][e1]-NominalMC->GetBinContent(e0,e1))*(MCReconstructedEvents[f0][f1]-NominalMC->GetBinContent(f0,f1));
	      //}
	    //}	    
	  //}
	}
      }
    }
    else if(ErrorType==3){
      for(int e0=0;e0<NBinsMom;e0++){//loop over effect 0
	for(int e1=0;e1<NBinsAngle;e1++){//loop over effect 1
	  HitEfficiencyFunctions->cd();
	  ErrorHitEfficiency[e0][e1]->Fit(Form("fErrorHitEfficiency[%d][%d]",e0,e1),"RQ");
	  ErrorHitEfficiency[e0][e1]->Write();
	  cout<<"check function before estimation systematic error"<<endl;
	  
	  //Error_Minus[ErrorType]->SetBinContent(e0,e1,-TMath::Abs(fErrorHitEfficiency[e0][e1]
	}
      }
    }
    else if(ErrorType>=7 && ErrorType<=Systematics_Detector_End){
      for(int e0=0;e0<NBinsMom;e0++){//loop over effect 0
	for(int e1=0;e1<NBinsAngle;e1++){//loop over effect 1
	  file->cd();
	  double ePlus=0;
	  double eMinus=0;
	  for(int ibin=1;ibin<=MCContent[ErrorType][e0][e1]->GetNbinsX();ibin++){
	    double Error=(DataContent[ErrorType][e0][e1]->GetBinContent(ibin)-MCContent[ErrorType][e0][e1]->GetBinContent(ibin));
	    if( Error > ePlus ) ePlus=Error;
	    else if( (-Error) > eMinus ) eMinus=Error;
	    for(int f0=0;f0<NBinsMom;f0++){//loop over effect 0
	      for(int f1=0;f1<NBinsAngle;f1++){//loop over effect 1
		double Error2=(DataContent[ErrorType][f0][f1]->GetBinContent(ibin)-MCContent[ErrorType][f0][f1]->GetBinContent(ibin));
		//Covariance[ErrorType][ErrorType][e0][e1][f0][f1]+=(1./(NE[ErrorType]-1.))*(NominalMC->GetBinContent(e0,e1)*(1+Error)-NominalMC->GetBinContent(e0,e1))*(NominalMC->GetBinContent(f0,f1)*(1+Error2)-NominalMC->GetBinContent(f0,f1));
		CovarianceReduced[ErrorType][e0][e1][f0][f1]+=(1./(NE[ErrorType]-1.))*(NominalMC->GetBinContent(e0,e1)*(1+Error)-NominalMC->GetBinContent(e0,e1))*(NominalMC->GetBinContent(f0,f1)*(1+Error2)-NominalMC->GetBinContent(f0,f1));
	      }
	    }
	  }
	Error_Minus[ErrorType]->SetBinContent(e0,e1,ePlus);
	Error_Plus[ErrorType]->SetBinContent(e0,e1,eMinus);
	DataMCErrorFunctions->cd();
	MCContent[ErrorType][e0][e1]->Write();
	DataContent[ErrorType][e0][e1]->Write();
	//Error_Minus[ErrorType]->SetBinContent(e0,e1,-TMath::Abs(fErrorHitEfficiency[e0][e1]

	}
      }
    }
    else if(ErrorType==16){
      for(int e0=0;e0<NBinsMom;e0++){//loop over effect 0
	for(int e1=0;e1<NBinsAngle;e1++){//loop over effect 1
	  FluxEventFunctions->cd();
	  ErrorFlux[e0][e1]->Fit(Form("fErrorFlux[%d][%d]",e0,e1),"RQ");
	  ErrorFlux[e0][e1]->Write();

	  Error_Minus[ErrorType]->SetBinContent(e0,e1,-fErrorFlux[e0][e1]->GetParameter(2));
	  Error_Plus[ErrorType]->SetBinContent(e0,e1,fErrorFlux[e0][e1]->GetParameter(2));
	}
      }
    }
    else if(ErrorType>=Systematics_Xsec_Start && ErrorType<=Systematics_Xsec_End){      
      //create the spline
      for(int e0=0;e0<NBinsMom;e0++){//loop over effect 0
	for(int e1=0;e1<NBinsAngle;e1++){//loop over effect 1
	  XSEventFunctions->cd();
	  gErrorXS[ErrorType-Systematics_Xsec_Start][e0][e1] = new TGraph(NXsecVariations,xXS[ErrorType-Systematics_Xsec_Start][e0][e1],yXS[ErrorType-Systematics_Xsec_Start][e0][e1]);
	  gErrorXS[ErrorType-Systematics_Xsec_Start][e0][e1]->Write(Form("gErrorXS[%d][%d][%d]",ErrorType-Systematics_Xsec_Start,e0,e1));
	  sErrorXS[ErrorType-Systematics_Xsec_Start][e0][e1] = new TSpline3(Form("sErrorXS[%d][%d][%d]",ErrorType-Systematics_Xsec_Start,e0,e1),gErrorXS[ErrorType-Systematics_Xsec_Start][e0][e1]);
	  sErrorXS[ErrorType-Systematics_Xsec_Start][e0][e1]->Write(Form("sErrorXS_%d_%d_%d",ErrorType-Systematics_Xsec_Start,e0,e1)); 
	}
      }
      cout<<"the end"<<endl;
    }
    
    for(int e0=0;e0<NBinsMom;e0++){//loop over effect 0
      for(int e1=0;e1<NBinsAngle;e1++){//loop over effect 1
	for(int f0=0;f0<NBinsMom;f0++){//loop over effect 0
	  for(int f1=0;f1<NBinsAngle;f1++){//loop over effect 1
	    //cout<<Covariance[ErrorType][ErrorType][f0][f1][f0][f1]<<endl;
	    //double Diagonal=Covariance[ErrorType][ErrorType][e0][e1][e0][e1]*Covariance[ErrorType][ErrorType][f0][f1][f0][f1];
	    //Correlation[ErrorType][ErrorType][e0][e1][f0][f1]=Covariance[ErrorType][ErrorType][e0][e1][f0][f1];
	    //if(Diagonal!=0) Correlation[ErrorType][ErrorType][e0][e1][f0][f1]/=pow(Diagonal,1/2);
	    double Diagonal=CovarianceReduced[ErrorType][e0][e1][e0][e1]*CovarianceReduced[ErrorType][f0][f1][f0][f1];
	    CorrelationReduced[ErrorType][e0][e1][f0][f1]=CovarianceReduced[ErrorType][e0][e1][f0][f1];
	    if(Diagonal!=0) CorrelationReduced[ErrorType][e0][e1][f0][f1]/=pow(Diagonal,1/2);
	  }
	}
      }
    }
    
    if(ErrorType<Systematics_Xsec_Start){
      file->cd();
      Error_Plus[ErrorType]->Write();
      Error_Minus[ErrorType]->Write(); 
    }
  }
  

 
  //#########################SPECIAL TREATMENT FOR XSECTION SOURCE: THE CORRELATION IS ALSO CHECKED BETWEEN THE ERROR SOUCRES (NOT ONLY THE BINS)
  
  if(EndError>=Systematics_Xsec_Start){
    //cout<<"hello"<<endl;
  //Starts the toy experiments:

  int NBinsTotal=NBinsMom*NBinsAngle;
  double Error;
  double NEventsXS[NBinsTotal];
  int NToysXsec=500;
  TRandom3 * rxs = new TRandom3();
  
  for(int s1=0;s1<=EndError-Systematics_Xsec_Start;s1++){
  //for(int s1=0;s1<=0;s1++){//TEMP
      cout<<"source tested="<<s1+Systematics_Xsec_Start<<endl;

      
      for(int nt=0;nt<NToysXsec;nt++){
	if(nt%100==0) cout<<"toy #"<<nt<<endl;
	Error=10;

      while(TMath::Abs(Error)>3) Error=rxs->Gaus(0,1);//My interpolation doesn't go further away than -+3sigma. Therefore, only keep toy experiment inside these values.
      for(int e0=0;e0<NBinsMom;e0++){//loop over effect 0
	for(int e1=0;e1<NBinsAngle;e1++){//loop over effect 1
	  int bin1=NBinsAngle*e0+e1;
	  NEventsXS[bin1]=NominalMC->GetBinContent(e0,e1)*sErrorXS[s1][e0][e1]->Eval(Error);
	  


	  
	  //if(e0==4 && e1==4) cout<<"Error="<<Error<<", "<<NEventsXS[bin1]-NominalMC->GetBinContent(e0,e1)<<", value="<<sErrorXS[2][4][4]->Eval(Error)<<endl;
	  for(int f0=0;f0<NBinsMom;f0++){//loop over effect 0
	    for(int f1=0;f1<NBinsAngle;f1++){//loop over effect 1
	      int bin2=NBinsAngle*f0+f1;
	      NEventsXS[bin2]=NominalMC->GetBinContent(f0,f1)*sErrorXS[s1][f0][f1]->Eval(Error);
	      //CovarianceReduced[e0][e1][f0][f1]+=(1./(NToysXsec-1.))*(NEventsXS[bin1]-NominalMC->GetBinContent(e0,e1))*(NEventsXS[bin2]-NominalMC->GetBinContent(f0,f1)); 



	      
	      CovarianceReduced[s1][e0][e1][f0][f1]+=(1./(NToysXsec-1.))*(NEventsXS[bin1]-NominalMC->GetBinContent(e0,e1))*(NEventsXS[bin2]-NominalMC->GetBinContent(f0,f1)); 
	      CovarianceXS[e0][e1][f0][f1]+=(1./(NToysXsec-1.))*(NEventsXS[bin1]-NominalMC->GetBinContent(e0,e1))*(NEventsXS[bin2]-NominalMC->GetBinContent(f0,f1)); 
	      //Covariance[Systematics_Xsec_Start+s1][Systematics_Xsec_Start+s1][e0][e1][f0][f1]+=(1./(NToysXsec-1.))*(NEventsXS[bin1]-NominalMC->GetBinContent(e0,e1))*(NEventsXS[bin2]-NominalMC->GetBinContent(f0,f1)); 
	      
	      //CovarianceReduced[e0][e1][f0][f1]+=(1./(NToysXsec-1.))*(NEventsXS[bin1]-sErrorXS[s1][e0][e1]->Eval(0))*(NEventsXS[bin2]-sErrorXS[s1][f0][f1]->Eval(0)); 

	    }
	  }	
	}
      }
      }
    for(int e0=0;e0<NBinsMom;e0++){//loop over effect 0
      for(int e1=0;e1<NBinsAngle;e1++){//loop over effect 1
	//double err=TMath::Sqrt(CovarianceReduced[s1][e0][e1][e0][e1]);
	double err=TMath::Sqrt(CovarianceXS[e0][e1][e0][e1]);
	if(NominalMC->GetBinContent(e0,e1)!=0) err/=NominalMC->GetBinContent(e0,e1);
	Error_Minus[Systematics_Xsec_Start+s1]->SetBinContent(e0,e1,-err);
	Error_Plus[Systematics_Xsec_Start+s1]->SetBinContent(e0,e1,err);
	
	//cout<<"Error="<<1e6*TMath::Sqrt(CovarianceReduced[e0][e1][e0][e1])<<endl;
	
	  for(int f0=0;f0<NBinsMom;f0++){//loop over effect 0
	    for(int f1=0;f1<NBinsAngle;f1++){//loop over effect 1
	      double Diagonal=CovarianceXS[e0][e1][e0][e1]*CovarianceXS[f0][f1][f0][f1];
	      if(Diagonal!=0) CorrelationXS[e0][e1][f0][f1]/=pow(Diagonal,1/2);
	      //double Diagonal=Covariance[Systematics_Xsec_Start+s1][Systematics_Xsec_Start+s1][e0][e1][e0][e1]*Covariance[Systematics_Xsec_Start+s1][Systematics_Xsec_Start+s1][f0][f1][f0][f1];
	      //if(Diagonal!=0) Correlation[Systematics_Xsec_Start+s1][Systematics_Xsec_Start+s1][e0][e1][f0][f1]/=pow(Diagonal,1/2);
	      //double Diagonal=CovarianceReduced[s1][e0][e1][e0][e1]*CovarianceReduced[s1][f0][f1][f0][f1];
	      //if(Diagonal!=0) CorrelationReduced[s1][e0][e1][f0][f1]/=pow(Diagonal,1/2);
	      
	    }
	  }
      }
    }
    file->cd();
    Error_Minus[Systematics_Xsec_Start+s1]->Write();
    Error_Plus[Systematics_Xsec_Start+s1]->Write();

    
 
  }
  }

 
  //#########################################DRAWING PART################################
  TBox * boxsliceErrorStat_RecMom[NBinsMom][NBinsAngle];
  TBox * boxsliceErrorFlux_RecMom[NBinsMom][NBinsAngle];
  TBox * boxsliceErrorXS_RecMom[NBinsMom][NBinsAngle];

  TBox * boxsliceErrorStat_RecAngle[NBinsMom][NBinsAngle];
  TBox * boxsliceErrorFlux_RecAngle[NBinsMom][NBinsAngle];
  TBox * boxsliceErrorXS_RecAngle[NBinsMom][NBinsAngle];

  TBox * boxErrorStat_RecMom[NBinsMom];
  TBox * boxErrorFlux_RecMom[NBinsMom];
  TBox * boxErrorXS_RecMom[NBinsMom];

  TBox * boxErrorStat_RecAngle[NBinsAngle];
  TBox * boxErrorFlux_RecAngle[NBinsAngle];
  TBox * boxErrorXS_RecAngle[NBinsAngle];

  
  //###################################CREATE 1D SLICE DISTRIBUTION##################"
  TH1D * sliceNominalMC_RecMom[NBinsAngle];
  TH1D * sliceNominalMC_RecAngle[NBinsMom];
  for(int e1=0;e1<NBinsAngle;e1++) sliceNominalMC_RecMom[e1] = (TH1D*) NominalMC->ProjectionX(Form("sliceNominalMC_RecMom[%d]",e1),e1+1,e1+1);
  for(int e0=0;e0<NBinsMom;e0++) sliceNominalMC_RecAngle[e0] = (TH1D*) NominalMC->ProjectionX(Form("sliceNominalMC_RecAngle[%d]",e0),e0+1,e0+1);
  //###################################


  
  //#########################################STAT ERROR################################
  cout<<"Statistical error:"<<endl;

  
  for(int e0=0;e0<NBinsMom;e0++){//loop over effect 0
    for(int e1=0;e1<NBinsAngle;e1++){//loop over effect 1
      double Value=0;double Error=0;double ErrorSquared=0;
      Value=NominalMC->GetBinContent(e0+1,e1+1);
      ErrorSquared=Value;
      Error=TMath::Sqrt(Value);

      NominalMC_RecMom->SetBinContent(e0+1,e1+1,Value);
      sliceNominalMC_RecMom[e1]->SetBinContent(e0+1,Value);
      sliceNominalMC_RecMom[e1]->SetBinError(e0+1,ErrorSquared);
      
      sliceNominalMC_RecAngle[e0]->SetBinContent(e1+1,Value);
      sliceNominalMC_RecAngle[e0]->SetBinError(e1+1,ErrorSquared);
      
      boxsliceErrorStat_RecMom[e0][e1] = new TBox(NominalMC->GetXaxis()->GetBinLowEdge(e0+1),Value-Error,NominalMC->GetXaxis()->GetBinUpEdge(e0+1),Value+Error);
      boxsliceErrorStat_RecMom[e0][e1]->SetFillColor(kRed);

      boxsliceErrorStat_RecAngle[e0][e1] = new TBox(NominalMC->GetYaxis()->GetBinLowEdge(e1+1),Value-Error,NominalMC->GetYaxis()->GetBinUpEdge(e1+1),Value+Error);
      boxsliceErrorStat_RecAngle[e0][e1]->SetFillColor(kRed);
    }
  }


  for(int e0=0;e0<NBinsMom;e0++){//loop over effect 0
    
    double Value=0;double Error=0;double ErrorSquared=0;
    for(int e1=0;e1<NBinsAngle;e1++){//loop over effect 1
      Value+=NominalMC->GetBinContent(e0+1,e1+1);
    }
    ErrorSquared=Value;
      
    Error=TMath::Sqrt(Value);
    cout<<"Mom="<<BinningRecMom[e0]<<", value="<<Value<<", "<<Error<<endl;
    NominalMC_RecMom->SetBinContent(e0+1,Value);
    NominalMC_RecMom->SetBinError(e0+1,ErrorSquared);

    boxErrorStat_RecMom[e0] = new TBox(NominalMC_RecMom->GetXaxis()->GetBinLowEdge(e0+1),Value-Error,NominalMC_RecMom->GetXaxis()->GetBinUpEdge(e0+1),Value+Error);
    boxErrorStat_RecMom[e0]->SetFillColor(kRed);
  }

  for(int e1=0;e1<NBinsAngle;e1++){//loop over effect 0

    double Value=0;double Error=0;double ErrorSquared=0;
    for(int e0=0;e0<NBinsMom;e0++){//loop over effect 1
      Value+=NominalMC->GetBinContent(e0+1,e1+1);
    }
    ErrorSquared=Value;
      
    Error=TMath::Sqrt(Value);
    cout<<"Angle="<<BinningRecAngle[e1]<<", value="<<Value<<", "<<Error<<endl;
    NominalMC_RecAngle->SetBinContent(e1+1,Value);
    NominalMC_RecAngle->SetBinError(e1+1,ErrorSquared);

    boxErrorStat_RecAngle[e1] = new TBox(NominalMC_RecAngle->GetXaxis()->GetBinLowEdge(e1+1),Value-Error,NominalMC_RecAngle->GetXaxis()->GetBinUpEdge(e1+1),Value+Error);
    boxErrorStat_RecAngle[e1]->SetFillColor(kRed);
  }
  //#########################################END OF STAT ERROR################################

  
  
  //#########################################XS ERROR################################
  if(EndError>=Systematics_Xsec_Start){
    cout<<"Xsec error:"<<endl;

    for(int e0=0;e0<NBinsMom;e0++){//loop over effect 0
      for(int e1=0;e1<NBinsAngle;e1++){//loop over effect 1
	double Value=0;double Error=0;double ErrorSquared=0;
	Value=NominalMC->GetBinContent(e0+1,e1+1);
	ErrorSquared=NominalMC->GetBinContent(e0+1,e1+1)+CovarianceXS[e0][e1][e0][e1];
	Error=TMath::Sqrt(ErrorSquared);
	
	NominalMC->SetBinError(e0+1,e1+1,ErrorSquared);
	sliceNominalMC_RecMom[e1]->SetBinError(e0+1,ErrorSquared);
	sliceNominalMC_RecAngle[e0]->SetBinError(e1+1,ErrorSquared);
	
	boxsliceErrorXS_RecMom[e0][e1] = new TBox(NominalMC->GetXaxis()->GetBinLowEdge(e0+1),Value-Error,NominalMC->GetXaxis()->GetBinUpEdge(e0+1),Value+Error);
	boxsliceErrorXS_RecMom[e0][e1]->SetFillColor(kGreen);
	
	boxsliceErrorXS_RecAngle[e0][e1] = new TBox(NominalMC->GetYaxis()->GetBinLowEdge(e1+1),Value-Error,NominalMC->GetYaxis()->GetBinUpEdge(e1+1),Value+Error);
	boxsliceErrorXS_RecAngle[e0][e1]->SetFillColor(kGreen);
      }
    }
  
  for(int e0=0;e0<NBinsMom;e0++){//loop over effect 0
    double Value=0;double ErrorSquared=0;double Error=0;
    Value=NominalMC_RecMom->GetBinContent(e0+1);    
    ErrorSquared=NominalMC_RecMom->GetBinError(e0+1);    
    
    for(int e1=0;e1<NBinsAngle;e1++){//loop over effect 1
      for(int f1=0;f1<NBinsAngle;f1++){//loop over effect 1
	ErrorSquared+=CovarianceXS[e0][e1][e0][f1];      
      }
    }
    Error=TMath::Sqrt(ErrorSquared);
    cout<<"Mom="<<BinningRecMom[e0]<<", value="<<Value<<", "<<Error<<endl;
    //NominalMC_RecMom->SetBinContent(e0+1,Value);
    NominalMC_RecMom->SetBinError(e0+1,ErrorSquared);

    boxErrorXS_RecMom[e0] = new TBox(NominalMC_RecMom->GetXaxis()->GetBinLowEdge(e0+1),NominalMC_RecMom->GetBinContent(e0+1)-Error,NominalMC_RecMom->GetXaxis()->GetBinUpEdge(e0+1),NominalMC_RecMom->GetBinContent(e0+1)+Error);
    boxErrorXS_RecMom[e0]->SetFillColor(kGreen);
  }
  
  for(int e1=0;e1<NBinsAngle;e1++){//loop over effect 0
    double Value=0;double ErrorSquared=0;double Error=0;
    Value=NominalMC_RecMom->GetBinContent(e1+1);    
    ErrorSquared=NominalMC_RecMom->GetBinError(e1+1);    
    
    for(int e0=0;e0<NBinsMom;e0++){//loop over effect 1
      for(int f0=0;f0<NBinsMom;f0++){//loop over effect 1
	ErrorSquared+=CovarianceXS[e0][e1][f0][e1];      
      }
    }
    Error=TMath::Sqrt(ErrorSquared);
    cout<<"Angle="<<BinningRecAngle[e1]<<", value="<<Value<<", "<<Error<<endl;
    //NominalMC_RecAngle->SetBinContent(e1+1,Value);
    NominalMC_RecAngle->SetBinError(e1+1,ErrorSquared);

    boxErrorXS_RecAngle[e1] = new TBox(NominalMC_RecAngle->GetXaxis()->GetBinLowEdge(e1+1),NominalMC_RecAngle->GetBinContent(e1+1)-Error,NominalMC_RecAngle->GetXaxis()->GetBinUpEdge(e1+1),NominalMC_RecAngle->GetBinContent(e1+1)+Error);
    boxErrorXS_RecAngle[e1]->SetFillColor(kGreen);
  }
  }
  //#########################################END OF XS ERROR################################

  
  
  //#########################################FLUX ERROR################################
  if(EndError>=Systematics_Flux_Start){
    cout<<"Flux error:"<<endl;
    int ErrorType=16;

    for(int e0=0;e0<NBinsMom;e0++){//loop over effect 0
      for(int e1=0;e1<NBinsAngle;e1++){//loop over effect 1
	double Value=0;double Error=0;double ErrorSquared=0;
	Value=NominalMC->GetBinContent(e0+1,e1+1);
	ErrorSquared=NominalMC->GetBinContent(e0+1,e1+1)+CovarianceFlux[e0][e1][e0][e1];
	Error=TMath::Sqrt(ErrorSquared);
	
	NominalMC->SetBinError(e0+1,e1+1,ErrorSquared);
	sliceNominalMC_RecMom[e1]->SetBinError(e0+1,ErrorSquared);
	sliceNominalMC_RecAngle[e0]->SetBinError(e1+1,ErrorSquared);
	
	boxsliceErrorFlux_RecMom[e0][e1] = new TBox(NominalMC->GetXaxis()->GetBinLowEdge(e0+1),Value-Error,NominalMC->GetXaxis()->GetBinUpEdge(e0+1),Value+Error);
	boxsliceErrorFlux_RecMom[e0][e1]->SetFillColor(kBlue);
	
	boxsliceErrorFlux_RecAngle[e0][e1] = new TBox(NominalMC->GetYaxis()->GetBinLowEdge(e1+1),Value-Error,NominalMC->GetYaxis()->GetBinUpEdge(e1+1),Value+Error);
	boxsliceErrorFlux_RecAngle[e0][e1]->SetFillColor(kBlue);
      }
    }

    for(int e0=0;e0<NBinsMom;e0++){//loop over effect 0
      double Value=0;double ErrorSquared=0;double Error=0;
	Value=NominalMC_RecMom->GetBinContent(e0+1);
	ErrorSquared=NominalMC_RecMom->GetBinError(e0+1);

      for(int e1=0;e1<NBinsAngle;e1++){//loop over effect 1

	for(int f1=0;f1<NBinsAngle;f1++){//loop over effect 1
	  //ErrorSquared+=Covariance[ErrorType][ErrorType][e0][e1][e0][f1];      
	  ErrorSquared+=CovarianceFlux[e0][e1][e0][f1];
	  //cout<<ErrorSquared<<endl;
	  //if(CovarianceFlux[e0][e1][e0][f1]!=0) cout<<CovarianceFlux[e0][e1][e0][f1]<<endl;
	}
      }
      Error=TMath::Sqrt(ErrorSquared);
      cout<<"Flux error, Mom="<<BinningRecMom[e0]<<", value="<<Value<<", "<<Error<<endl;
      boxErrorFlux_RecMom[e0] = new TBox(NominalMC_RecMom->GetXaxis()->GetBinLowEdge(e0+1),Value-Error,NominalMC_RecMom->GetXaxis()->GetBinUpEdge(e0+1),Value+Error);
      boxErrorFlux_RecMom[e0]->SetFillColor(kBlue);
      NominalMC_RecMom->SetBinError(e0+1,ErrorSquared);
    }
    
    for(int e1=0;e1<NBinsAngle;e1++){//loop over effect 0
      double Value=0;double ErrorSquared=0;double Error=0;
	Value=NominalMC_RecAngle->GetBinContent(e1+1);
	ErrorSquared=NominalMC_RecAngle->GetBinError(e1+1);

      for(int e0=0;e0<NBinsMom;e0++){//loop over effect 1

	for(int f0=0;f0<NBinsMom;f0++){//loop over effect 1
	  //ErrorSquared+=Covariance[ErrorType][ErrorType][e0][e1][e0][f1];      
	  ErrorSquared+=CovarianceFlux[e0][e1][f0][e1];
	  //cout<<ErrorSquared<<endl;
	  //if(CovarianceFlux[e0][e1][e0][f1]!=0) cout<<CovarianceFlux[e0][e1][e0][f1]<<endl;
	}
      }
      Error=TMath::Sqrt(ErrorSquared);
      cout<<"Flux error, Angle="<<BinningRecAngle[e1]<<", value="<<Value<<", "<<Error<<endl;
      boxErrorFlux_RecAngle[e1] = new TBox(NominalMC_RecAngle->GetXaxis()->GetBinLowEdge(e1+1),Value-Error,NominalMC_RecAngle->GetXaxis()->GetBinUpEdge(e1+1),Value+Error);
      boxErrorFlux_RecAngle[e1]->SetFillColor(kBlue);
      NominalMC_RecAngle->SetBinError(e1+1,ErrorSquared);
    }
    
  }

  //#########################################END FLUX ERROR################################

  //#####################################PUT BACK TOTAL ERROR TO SQRT (COVARIANCE)################################
  for(int e0=0;e0<NBinsMom;e0++){//loop over effect 0
    for(int e1=0;e1<NBinsAngle;e1++){//loop over effect 1
      double Value=0;double ErrorSquared=0;double Error=0;
      ErrorSquared=NominalMC->GetBinError(e0+1,e1+1);
      Error=TMath::Sqrt(ErrorSquared);
      NominalMC->SetBinError(e0+1,e1+1,Error);
      sliceNominalMC_RecMom[e1]->SetBinError(e0+1,Error);
      sliceNominalMC_RecAngle[e0]->SetBinError(e1+1,Error);
    }
  }

  for(int e0=0;e0<NBinsMom;e0++){//loop over effect 0
    double Value=0;double ErrorSquared=0;double Error=0;
    ErrorSquared=NominalMC_RecMom->GetBinError(e0+1);
    Error=TMath::Sqrt(ErrorSquared);
    NominalMC_RecMom->SetBinError(e0+1,Error);
  }
  for(int e1=0;e1<NBinsAngle;e1++){//loop over effect 0
    double Value=0;double ErrorSquared=0;double Error=0;
    ErrorSquared=NominalMC_RecAngle->GetBinError(e1+1);
    Error=TMath::Sqrt(ErrorSquared);
    NominalMC_RecAngle->SetBinError(e1+1,Error);
  }
  //#####################################END OF PUT BACK TOTAL ERROR TO SQRT (COVARIANCE)################################


  
  //#####################################DRAWING OF 1D MOM & ANGLE PLOTS################################
  
  TCanvas * csliceRecMom[NBinsAngle];

  for(int e1=0;e1<NBinsAngle;e1++){//loop over effect 0
    csliceRecMom[e1]= new TCanvas(Form("csliceRecMom[%d]",e1));
    sliceNominalMC_RecMom[e1]->Draw("E1");
    for(int e0=0;e0<NBinsMom;e0++){//loop over effect 0
      if(EndError>=Systematics_Flux_Start) boxsliceErrorFlux_RecMom[e0][e1]->Draw("same");
      if(EndError>=Systematics_Xsec_Start) boxsliceErrorXS_RecMom[e0][e1]->Draw("same");
      boxsliceErrorStat_RecMom[e0][e1]->Draw("same");
    }
    sliceNominalMC_RecMom[e1]->Draw("E1same");
    sliceNominalMC_RecMom[e1]->GetXaxis()->SetTitle("d_{#mu} (cm)");
    sliceNominalMC_RecMom[e1]->GetYaxis()->SetTitle("Number of events");
    sliceNominalMC_RecMom[e1]->SetLineColor(1);
    sliceNominalMC_RecMom[e1]->SetLineWidth(2);
    sliceNominalMC_RecMom[e1]->GetYaxis()->SetTitleOffset(1.3);
    csliceRecMom[e1]->Write(Form("Canvas_Nominal_RecMom_slice%d",e1));
  }

  TCanvas * cRecMom = new TCanvas("cRecMom");
  NominalMC_RecMom->Draw("E1");
  for(int e0=0;e0<NBinsMom;e0++){//loop over effect 0
    if(EndError>=Systematics_Flux_Start) boxErrorFlux_RecMom[e0]->Draw("same");
    if(EndError>=Systematics_Xsec_Start) boxErrorXS_RecMom[e0]->Draw("same");
    boxErrorStat_RecMom[e0]->Draw("same");
  }
  NominalMC_RecMom->Draw("E1same");
  NominalMC_RecMom->GetXaxis()->SetTitle("d_{#mu} (cm)");
  NominalMC_RecMom->GetYaxis()->SetTitle("Number of events");
  NominalMC_RecMom->SetLineColor(1);
  NominalMC_RecMom->SetLineWidth(2);
  NominalMC_RecMom->GetYaxis()->SetTitleOffset(1.3);
  cRecMom->Write("Canvas_Nominal_RecMom");
  
  TCanvas * cRecAngle = new TCanvas("cRecAngle");
  NominalMC_RecAngle->Draw("E1");
  for(int e0=0;e0<NBinsAngle;e0++){//loop over effect 0
    if(EndError>=Systematics_Flux_Start) boxErrorFlux_RecAngle[e0]->Draw("same");
      if(EndError>=Systematics_Xsec_Start) boxErrorXS_RecAngle[e0]->Draw("same");
    boxErrorStat_RecAngle[e0]->Draw("same");
  }
  NominalMC_RecAngle->Draw("E1same");
  NominalMC_RecAngle->SetLineColor(1);
  NominalMC_RecAngle->SetLineWidth(2);
  NominalMC_RecAngle->GetXaxis()->SetTitle("#theta_{#mu} (cm)");
  NominalMC_RecAngle->GetYaxis()->SetTitle("Number of events");
  NominalMC_RecAngle->GetYaxis()->SetTitleOffset(1.3);
  
  cRecAngle->Write("Canvas_Nominal_RecAngle");
  //#####################################END OF DRAWING################################

  //#########################################END OF DRAWING PART################################

  
  NominalMC_RecMom->Write();
  NominalMC_RecAngle->Write();
  NominalMC->Write();
  file->Close();
  return 0;
}
