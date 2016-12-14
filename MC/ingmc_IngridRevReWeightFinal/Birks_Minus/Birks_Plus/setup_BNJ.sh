source $HOME/Run_At_Start.bashrc

#Set ND280 software package PATH
export ND280ROOT=/home/bquilain/T2KSoftware2/ROOT/v5r22p00n00
export ND280CLHEP=/home/bquilain/T2KSoftware2/CLHEP/v2r0p3
export ND280GEANT=/home/bquilain/T2KSoftware2/GEANT/v9r2p01n00


#Set Env various by cmt
source $ND280GEANT/cmt/setup.sh
source $ND280ROOT/cmt/setup.sh
source $ND280CLHEP/cmt/setup.sh

#Set MY Env
export G4WORKDIR=`pwd`
export G4BIN=$G4WORKDIR/bin
export G4TMP=$G4WORKDIR/tmp
export G4NEUTRONHPDATA=~/T2KSoftware2/GEANT/v9r2p01n00/Linux-x86_64/G4NDL4.2