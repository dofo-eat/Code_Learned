NowTime=`date +%s`

TimeSec=$[${NowTime} - ${LoginTime}]
Time=$[ ${TimeSec} / 60 ]

echo "Login for ${Time} min."
