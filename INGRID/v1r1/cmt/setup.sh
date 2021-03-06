# echo "Setting INGRID v1r1 in /home/ingrid/data_process/offline/work"

if test "${CMTROOT}" = ""; then
  CMTROOT=/data/home/ingrid/data_process/offline/CMT/v1r20p20081118; export CMTROOT
fi
. ${CMTROOT}/mgr/setup.sh

tempfile=`${CMTROOT}/mgr/cmt -quiet build temporary_name`
if test ! $? = 0 ; then tempfile=/tmp/cmt.$$; fi
${CMTROOT}/mgr/cmt setup -sh -pack=INGRID -version=v1r1 -path=/home/bquilain/Ingrid_Process  -no_cleanup $* >${tempfile}; . ${tempfile}
/bin/rm -f ${tempfile}

