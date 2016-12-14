
//##### Standard C++ lib. ######
#include<iostream>
#include<sstream>
#include<fstream>
#include<math.h>
using namespace std;
#include <iomanip.h>
#include <sys/stat.h>
//##### Root Library ###########
#include <TROOT.h>
#include <TStyle.h>
#include <TH1F.h>
#include <TApplication.h>
#include <TGraphErrors.h>
#include <TFile.h>
#include <TCanvas.h>
#include <TTree.h>
#include <TClonesArray.h>
#include <TObject.h>
#include <TEventList.h>
#include <TBranch.h>
#include <TSystem.h>
#include <TBrowser.h>
#include <TMath.h>
#include <TLatex.h>
//##### INGRID Library #########
#include "INGRIDEVENTSUMMARY.h"
#include "IngridHitSummary.h"
#include "IngridSimHitSummary.h"
#include "IngridBasicReconSummary.h"

const static float DISTANCE_MODULE = 150;
const static float WIDTH_MODULE = 120;

int main(int argc,char *argv[]){
  TROOT        root ("GUI","GUI");
  TApplication app  ("App",0,0);

  Int_t c=-1;  char FileName[300]; char Output[300];
  Int_t run_number=0;
  bool  mc = false;
  sprintf(Output,"temp.root");
  while ((c = getopt(argc, argv, "f:mo:")) != -1) {
    switch(c){
    case 'f':
      sprintf(FileName,"%s",optarg);
      break;

    case 'o':
      sprintf(Output,"%s",optarg);
      break;
    case 'm':
      mc=true;
      break;
    }
  }
  FileStat_t fs;
  cout<<"reading "<<FileName<<"....."<<endl;
  if(gSystem->GetPathInfo(FileName,fs)){
    cout<<"Cannot open file "<<FileName<<endl;
    exit(1);
  }
  double totalpot=0; 
  //#### Read ROOT File after basic reconstruction ######
  //#####################################################
  TFile*            rfile = new TFile(FileName,"read");
  TTree*             tree = (TTree*)rfile -> Get("tree");
  TBranch*          EvtBr = tree->GetBranch("fDefaultReco.");
  IngridEventSummary* evt = new IngridEventSummary();
  EvtBr                   ->SetAddress(&evt);
  tree                    ->SetBranchAddress("fDefaultReco.", &evt);
  int                nevt = (int)tree -> GetEntries();
  cout << "Total # of events = " << nevt <<endl;

  //#### Create file after calibration ######
  //#########################################
  TFile*            f = new TFile(Output,"recreate");

  f->cd();
  TDirectory* histdir = new TDirectory("histdir",
				       "dir. for histogram",
				       "");
  f->cd();
  histdir->Write();
  histdir->cd();

  TH1F* fHnevt = new TH1F("fHnevt", "fHnevt",14,0,14);
  fHnevt -> Sumw2();

  IngridBasicReconSummary*  basicrecon;
  IngridSimVertexSummary*   simver;
  float weight, norm, totcrsne;
  const static float Cons = 2.91e-12;

  for(int ievt = 0; ievt < nevt; ++ievt){
    if( ievt%1000 == 0 )cout<<ievt<<endl;
    evt  -> Clear();
    tree -> GetEntry(ievt);
    
    if(mc){
      simver = (IngridSimVertexSummary*) (evt->GetSimVertex(0));
      weight   = simver -> weight;
      norm     = simver -> norm;
      totcrsne = simver -> totcrsne;

    }

    for( int ibasic=0; ibasic < evt -> NIngridBasicRecons(); ibasic++ ){

      basicrecon = (IngridBasicReconSummary*) ( evt -> GetBasicRecon( ibasic ) );
      int hitmod = basicrecon -> hitmod;


      //### neutrino event ###
      //######################
      Bool_t  sigreg  = 
	(  basicrecon  -> layerpe > 6.5 ) &&
	(  basicrecon  -> nactpln >   2 ) &&
	(  basicrecon  -> hastrk        ) &&
	(  basicrecon  -> matchtrk      ) &&
	( (  basicrecon  -> ontime        ) || mc) &&
	!(  basicrecon -> vetowtracking ) &&
	!(  basicrecon -> edgewtracking ) ;
      if( sigreg ){
	if( mc ){
	  fHnevt -> Fill(hitmod, norm*totcrsne*Cons);
	}
	else if(!mc){
	  fHnevt -> Fill(hitmod);
	}
      }

    }
  }


  //#### 
  float x[7]             = {0};
  float x_error[7]       = {0};
  float nent[2][7]={0};
  float nent_error[2][7] = {0}; 
  
  for(int i=0; i<2; i++){
    for(int j=0; j<7; j++){

      nent[i][j]           = fHnevt->GetBinContent(i*7+j+1);
      cout << nent[i][j] << endl;
      nent_error[i][j]     = fHnevt->GetBinError(i*7+j+1);
      x[j]       = ( j - 3 ) * DISTANCE_MODULE;
      //x_error[j] = 1.0 * WIDTH_MODULE / sqrt(3) / 2;
      x_error[j] = 0;
    }
  }
  f->cd();


  TGraphErrors *h  = new TGraphErrors(7, x,     nent[0],
				      x_error,nent_error[0]);

  TGraphErrors *v  = new TGraphErrors(7, x,  nent[1],
				      x_error, nent_error[1]);




  TH1F* fHhpro = new TH1F("fHhpro",
			  "horizontal profile",
			  1000,-500,500);
  TH1F* fHvpro = new TH1F("fHvpro",
			  "vertical profile",
			  1000,-500,500);
  TH1F* fHhcenter = new TH1F("fHhcenter","fHhcenter",
			     20000,-5,5);
  TH1F* fHvcenter = new TH1F("fHvcenter","fHvcenter",
			     20000,-5,5);


  fHhcenter -> Fill( 0.0, nent[1][3]*1.2);
  fHvcenter -> Fill(-1.9, nent[1][3]*1.2);
  fHhcenter -> SetLineStyle(2);
  fHvcenter -> SetLineStyle(2);
  fHhcenter -> SetLineColor(2);
  fHvcenter -> SetLineColor(2);


  //fHhcenter -> cd();
  //TPad* fpadn     = new TPad("fpadn", "fpadn",
  //		     0.2, 0.1, 0.3, 0.2);
  //fpadn -> Draw();
  //fpadn  -> cd();
  TLatex* ftexn = new TLatex();
  ftexn -> SetText(0.0, 0.0, "north");
  //ftexn -> Draw();


  fHhpro -> SetMaximum( nent[1][3]*1.2 );
  fHvpro -> SetMaximum( nent[1][3]*1.2 );
  fHhpro -> SetMinimum( 0 );
  fHvpro -> SetMinimum( 0 );
  fHhpro -> SetXTitle ("x[cm] from INGRID center");
  fHvpro -> SetXTitle ("y[cm] from INGRID center");
  fHhpro -> SetYTitle ("Number of events");
  fHvpro -> SetYTitle ("Number of events");


  h->SetName("hpro");
  h->Write();

  v->SetName("vpro");
  v->Write();


  f -> cd();
  f -> Write();
  f -> Close();

  rfile -> Close();

}
 
