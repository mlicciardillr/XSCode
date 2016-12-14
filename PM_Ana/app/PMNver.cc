#define TEST 1
//##### Standard C++ lib. ######
#include<iostream>
#include<sstream>
#include<fstream>
using namespace std;
#include <iomanip.h>
#include <sys/stat.h>
#include "math.h"
//##### Root Library ###########
#include <TROOT.h>
#include <TStyle.h>
#include <TH1.h>
#include <TH2.h>
#include <TApplication.h>
#include <TFile.h>
#include <TCanvas.h>
#include <TTree.h>
#include <TClonesArray.h>
#include <TObject.h>
#include <TEventList.h>
#include <TBranch.h>
#include <TSystem.h>
#include <TBrowser.h>
//##### INGRID Library #########
#include "INGRIDEVENTSUMMARY.h"
#include "IngridHitSummary.h"
#include "IngridSimHitSummary.h"
#include "IngridBasicReconSummary.h"
#include "BeamInfoSummary.h"
#include "PMAnaSummary.h"

PMAnaSummary* pmanasum;
//BeamInfoSummary*         beaminfo;
IngridSimVertexSummary*         simver;

ofstream outfile("npile.txt");

#define POTBIN 6
#define POTMAX 6

int nall[POTBIN];
int nnu[14],inttmp;
float weight;

TH1F *hnu = new TH1F("hnu","hnu",POTBIN,0,POTMAX);


/*
const int nMON = 12;
const int nDAY = 31;
const int nMOD = 14;


int    nSPILL[nMON][nDAY];
int    iNEVT[nMON][nDAY][nMOD];
int    iDMU [nMON][nDAY][nMOD];
double iPOT[nMON][nDAY];
double iMUMON[nMON][nDAY];
double MUXxPOT [nMON][nDAY];
double MUYxPOT [nMON][nDAY];
double MUX [nMON][nDAY];
double MUY [nMON][nDAY];

void  clear(){

  for(int imon=0; imon<nMON; imon++){
    for(int iday=0; iday<nDAY; iday++){
      for(int imod=0; imod<nMOD; imod++){
	iNEVT[imon][iday][imod]=0;
      }
      nSPILL[imon][iday]=0;
      iPOT[imon][iday]=0;
      iMUMON[imon][iday]=0;
      MUX[imon][iday]=0;
      MUY[imon][iday]=0;
      MUXxPOT[imon][iday]=0;
      MUXxPOT[imon][iday]=0;
    }
  }
}
*/


void  fill_ing(){
  if(//pmanasum->hastrk && pmanasum->matchtrk && 
     /*ingbasic->ontime &&*/ !(pmanasum->vetowtracking) &&
     !(pmanasum->edgewtracking) ){
    
    //int mod=0;
    //if(mod==16){
    nnu[0]++;
      //}

  }

  /*
  if(ingbasic->hastrk && ingbasic->matchtrk && 
     ingbasic->ontime && 
     ( (ingbasic->vetowtracking) || (ingbasic->edgewtracking) ) ){
    
    int mod=ingbasic->hitmod;
    int cyc=ingbasic->hitcyc;
    if(mod<14&&cyc>=4&&cyc<12){
      hmu->Fill(pot[cyc-4]);
      inttmp=pot[cyc-4]/POTMAX*POTBIN;
      nmu[mod][inttmp]++;

    }
      //iDMU[m][d][mod]++;
  }
  */

}

void check(){


  for(int mod=0;mod<1;mod++){   
    if(nnu[mod]>0){
      hnu->Fill(nnu[mod],weight);
    }
  }
  
  

}

void out(){

  TCanvas *c1= new TCanvas("c1","c1",0,0,600,400);
  hnu->Draw();
  c1->Print("Nvertex.C");
}

int main(int argc,char *argv[]){
  TROOT        root ("GUI","GUI");
  TApplication app  ("App",0,0);


  Int_t c=-1;  char FileName[300]; 
  //sprintf(Output,  "nevent.txt");
  sprintf(FileName,"temp.root");
  while ((c = getopt(argc, argv, "f:")) != -1) {
    switch(c){
    case 'f':
      sprintf(FileName,"%s",optarg);
      break;
      //case 'o':
      //sprintf(Output,"%s",optarg);
      //break;
    }
  }

  FileStat_t fs;
  cout<<"reading and processsing"<<FileName<<"....."<<endl;
  if(gSystem->GetPathInfo(FileName,fs)){
    cout<<"Cannot open file "<<FileName<<endl;
    exit(1);
  }

  //#### Read ROOT File after basic reconstruction ######
  //#####################################################
  TFile*            rfile = new TFile(FileName,"read");
  TTree*             tree = (TTree*)rfile -> Get("tree");
  TBranch*          EvtBr = tree->GetBranch("fDefaultReco.");
  IngridEventSummary* evt = new IngridEventSummary();
  EvtBr                   ->SetAddress(&evt);
  tree                    ->SetBranchAddress("fDefaultReco.", &evt);
  int                nevt = (int)tree -> GetEntries();

  //clear();
  for(int ievt=0; ievt<nevt; ievt++){

    memset(nnu,0,sizeof(nnu));
    //for(int ievt=0; ievt<30000; ievt++){
    if(ievt%10000==0)cout << ievt << endl;
    evt       -> Clear();
    tree      -> GetEntry(ievt);
    //beaminfo  = (BeamInfoSummary*)(evt->GetBeamSummary(0));
    simver  = (IngridSimVertexSummary*)( evt -> GetSimVertex(0) );
    weight = (simver->norm)*(simver->totcrsne);

    //int utime = beaminfo->trg_sec;
    //utime -= 3600 * 9;

    for(int ibasic = 0; ibasic < evt->NPMAnas(); ibasic++){
      pmanasum     = (PMAnaSummary*)(evt->GetPMAna(ibasic));
      fill_ing();
    }
    check();
  }//ievt
  out();

}
