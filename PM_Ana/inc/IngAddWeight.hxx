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
#include <TCanvas.h>
#include <TTree.h>
#include <TClonesArray.h>
#include <TObject.h>
#include <TEventList.h>
#include <TBranch.h>
#include <TH1.h>

#include <TGraph.h>
#include <TGaxis.h>
#include <TMarker.h>
#include <TText.h>
#include <TMath.h>
#include <TSpectrum.h>
#include <TBox.h>
#include <TLatex.h>
#include <TString.h>
#include <TSystem.h>

#include "TApplication.h"

//#include "root_setup.hxx"                                                    
#include "INGRIDEVENTSUMMARY.h"
#include "IngridHitSummary.h"
#include "IngridSimHitSummary.h"
#include "IngridSimVertexSummary.h"
#include "IngridSimParticleSummary.h"
#include "BeamInfoSummary.h"
#include "IngridBasicReconSummary.h"
#include "IngridConstants.h"

FileStat_t fs;

#define NUMU 0
#define NUMUBAR 1
#define NUE 2
#define NUEBAR 3
class Weight{
public:
  float Emin;
  float Emax;
  float weight;
};

vector<Weight> enuweight[4][14]; //Flavor, module
vector<Weight> unc_ing_fluka[4][14]; //Flavor, module
bool Get(vector<Weight>& v, string str){
  ifstream f( str.c_str() );
  float Emin, Emax, weight;
  Weight w;
  int i=0;
  while( f >> Emin >> Emax >> weight){
    w.Emin = Emin; w.Emax = Emax; w.weight = weight;
    v.push_back(w);
  }
  f.close();
  return true;
}

void Print(){
  vector<Weight> enuweight[4][14]; //Flavor, module
}


string path_enuweight = "/home/ingrid/EnuWeight/Result/GCALOR2FLUKA/";
void Set_enuweight(){
  for(int imod=0; imod<14; imod++){
    Get( enuweight[0][imod], Form( "%s/numu/module_%02d.txt", path_enuweight.c_str(), imod ) );
    Get( enuweight[1][imod], Form( "%s/numubar/module_%02d.txt", path_enuweight.c_str(), imod ) );
    Get( enuweight[2][imod], Form( "%s/nue/module_%02d.txt", path_enuweight.c_str(), imod ) );
  }
}
string path_hadpro = "/home/ingrid/EnuWeight/Result/HadronProduction/";
void Set_unc_ing_fluka(){
  for(int imod=0; imod<14; imod++){
    Get( unc_ing_fluka[0][imod], Form( "%s/numu/module_%02d.txt", path_hadpro.c_str(), imod ) );
    Get( unc_ing_fluka[1][imod], Form( "%s/numubar/module_%02d.txt", path_hadpro.c_str(), imod ));
  }
}

void Set(){
  Set_enuweight();
  Set_unc_ing_fluka();
}

float Return( vector<Weight>& w , float Enu){
  for(int i=0; i<w.size(); i++){
    if( w[i].Emin <  Enu*1000 && w[i].Emax >= Enu*1000 ){
      return w[i].weight;
    }
  }
  return -1.e-5;
}

float Get_Weight(int mode, int flavor, int mod, float Enu){
  if(mode==0)
    return Return( enuweight[flavor][mod] , Enu);
  if(mode==1)
    return Return( unc_ing_fluka[flavor][mod] , Enu );

  return -1.e-5;

}
