export INSTALLREPOSITORY=/home/bquilain/CC0pi_XS/NewXSCode/XSCode
export MCINPUTSTORAGE=/home/cvson/scraid2/neutfile5d3d2
export DATAINPUTSTORAGE=/export/scraid2/data/bquilain
export MCOUTPUTSTORAGE=/export/scraid2/data/bquilain/MCfiles
#export MCOUTPUTSTORAGE=/export/scraid4/data2/mlicciardi/PM_MCFiles/XSFileGenerator
export DATAOUTPUTSTORAGE=/export/scraid2/data/bquilain
export INGRIDSOFTWARE=/home/bquilain/T2KSoftware2
#Set ND280 software package PATH
export ND280ROOT=/home/bquilain/T2KSoftware2/ROOT/v5r22p00n00
export ND280CLHEP=/home/bquilain/T2KSoftware2/CLHEP/v2r0p3
export ND280GEANT=/home/bquilain/T2KSoftware2/GEANT/v9r2p01n00

export INGRIDSOFTWARE_INGRID=${INGRIDSOFTWARE}/INGRID
export INGRIDSOFTWARE_INGRIDFORMAT=${INGRIDSOFTWARE}/ingrid_format

export DATAOUTPUTSTORAGE_DST=$DATAOUTPUTSTORAGE/dst
export DATAOUTPUTSTORAGE_CALIB=$DATAOUTPUTSTORAGE/calib_root_file
export DATAOUTPUTSTORAGE_RECONSTRUCTED=$DATAOUTPUTSTORAGE/DataNew
export DATAOUTPUTSTORAGE_ROOT=$DATAOUTPUTSTORAGE/PM

source $INSTALLREPOSITORY/Run_At_Start.bashrc
#Set Env various by cmt
source $ND280GEANT/cmt/setup.sh
source $ND280ROOT/cmt/setup.sh
source $ND280CLHEP/cmt/setup.sh

#Set MY Env
#export G4WORKDIR=$INSTALLREPOSITORY
export G4WORKDIR=$INSTALLREPOSITORY/MC
export G4BIN=$G4WORKDIR/bin
export G4TMP=$G4WORKDIR/tmp
export G4NEUTRONHPDATA=~/T2KSoftware2/GEANT/v9r2p01n00/Linux-x86_64/G4NDL4.2
