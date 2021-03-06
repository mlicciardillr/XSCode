#ifndef Xsec_h
#define Xsec_h
#include<iostream>
#include<sstream>
#include<fstream>
using namespace std;
#include <iomanip>
#include <sys/stat.h>
#include <cmath>
#include "Hit.h"
#include "setup.h"

class Xsec{
 public:
  
  void Initialize();

  int DetermineFSI(int IsSand,int IsAnti,int IsNuE,int IsBkgH,int IsBkgV,IngridEventSummary * evt);
  void DetermineNuType(int IsSand,int IsAnti,int IsNuE,int IsBkgH,int IsBkgV,int nutype, int intmode);
    
  void LoadMuCLDistributions();
  
  double GetMuCL(TF1 * CL_Ing,TF1 * CL_PMIng,TF1 * CL_PMSci,vector <Hit3D> Vec, double dx, int TrackSample, bool SystematicPE, int RandomPE);
  double GetMuCL_Plan(TF1 * CL_Ing,TF1 * CL_PMIng,TF1 * CL_PMSci,vector <Hit3D> Vec, double dx, int TrackSample, bool SystematicPE, int RandomPE);
  
  void LoadInputFiles_UnfoldedData(char * InputName, double DataUnfoldedEvents[NBinsTrueMom][NBinsTrueAngle], double DataTrueEvents[NBinsTrueMom][NBinsTrueAngle]);
    
  void LoadInputFiles_OnlySelectedData(char * fDataName,double DataReconstructedEvents[NBinsRecMom][NBinsRecAngle]);
    
  void LoadInputFiles(char * fDataName,char * fMCName, double MCReconstructedEvents_TrueSignal[NBinsTrueMom][NBinsTrueAngle][NBinsRecMom][NBinsRecAngle], double DataReconstructedEvents[NBinsRecMom][NBinsRecAngle],double MCReconstructedEvents[NBinsRecMom][NBinsRecAngle], double MCReconstructedBkgEvents[NBinsRecMom][NBinsRecAngle], double Efficiency[NBinsTrueMom][NBinsTrueAngle], double *NumberOfPOT);

  void LoadNeutrinoFlux(TH1D * NeutrinoFlux);
  
  void BuildLikelihood(double vLikelihood[NBinsTrueMom][NBinsTrueAngle][NBinsRecMom][NBinsRecAngle], double vPriorMC[NBinsTrueMom][NBinsTrueAngle], double TrueEventsDistribution[NBinsTrueMom][NBinsTrueAngle], double MCReconstructedEvents_TrueSignal[NBinsTrueMom][NBinsTrueAngle][NBinsRecMom][NBinsRecAngle]);

  void BuildUnfolding(double vUnfolding[NBinsTrueMom][NBinsTrueAngle][NBinsRecMom][NBinsRecAngle], double vLikelihood[NBinsTrueMom][NBinsTrueAngle][NBinsRecMom][NBinsRecAngle], double vPrior[NBinsTrueMom][NBinsTrueAngle]);

  void ApplyUnfolding(double vPosteriorEvents[NBinsTrueMom][NBinsTrueAngle], double vUnfolding[NBinsTrueMom][NBinsTrueAngle][NBinsRecMom][NBinsRecAngle], double DataReconstructedEvents[NBinsRecMom][NBinsRecAngle], double MCReconstructedBkgEvents[NBinsRecMom][NBinsRecAngle]);

  void SetPrior(double vPriorNormalised[NBinsTrueMom][NBinsTrueAngle], double vPrior[NBinsTrueMom][NBinsTrueAngle],
double vInitialPriorMC[NBinsTrueMom][NBinsTrueAngle], double vInitialPrior[NBinsTrueMom][NBinsTrueAngle],double vPosterior[NBinsTrueMom][NBinsTrueAngle], bool PriorMC, double IterationStep);

  void GenerateStatisticalFluctuations(double DataReconstructedEvents[NBinsRecMom][NBinsRecAngle]);

  void GenerateMCFluctuations(double MCReconstructedEvents_TrueSignal[NBinsTrueMom][NBinsTrueAngle][NBinsRecMom][NBinsRecAngle],double RelativeSigma[NBinsTrueMom][NBinsTrueAngle][NBinsRecMom][NBinsRecAngle]);
};
#endif
