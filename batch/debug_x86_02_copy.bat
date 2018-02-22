echo off
rem -----------------------------------------------------
rem Copy Images, license, redistribute for Install
rem -----------------------------------------------------
mkdir ..\..\Aries-Desktop-MSVC2013-32bit-Debug\bin\Debug

rem -----------------------------------------------------
rem Copy Utility for Execute
rem -----------------------------------------------------
rem xcopy ..\reader\* 					..\..\Aries-Desktop-MSVC2013-32bit-Debug\bin\Debug\reader\* /e /h /k
copy ..\src\ffmpeg341\bin\avcodec-57.dll 		..\..\Aries-Desktop-MSVC2013-32bit-Debug\bin\Debug
copy ..\src\ffmpeg341\bin\avdevice-57.dll 		..\..\Aries-Desktop-MSVC2013-32bit-Debug\bin\Debug
copy ..\src\ffmpeg341\bin\avfilter-6.dll 		..\..\Aries-Desktop-MSVC2013-32bit-Debug\bin\Debug
copy ..\src\ffmpeg341\bin\avformat-57.dll 		..\..\Aries-Desktop-MSVC2013-32bit-Debug\bin\Debug
copy ..\src\ffmpeg341\bin\avutil-55.dll 		..\..\Aries-Desktop-MSVC2013-32bit-Debug\bin\Debug
copy ..\src\ffmpeg341\bin\postproc-54.dll 		..\..\Aries-Desktop-MSVC2013-32bit-Debug\bin\Debug
copy ..\src\ffmpeg341\bin\swresample-2.dll 		..\..\Aries-Desktop-MSVC2013-32bit-Debug\bin\Debug
copy ..\src\ffmpeg341\bin\swscale-4.dll 		..\..\Aries-Desktop-MSVC2013-32bit-Debug\bin\Debug

