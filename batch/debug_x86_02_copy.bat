echo off
rem -----------------------------------------------------
rem Copy Images, license, redistribute for Install
rem -----------------------------------------------------
mkdir ..\..\Aries-Desktop-MSVC2013-32bit-Debug\bin\Debug

rem -----------------------------------------------------
rem Copy Utility for Execute
rem -----------------------------------------------------
rem xcopy ..\reader\* 					..\..\Aries-Desktop-MSVC2013-32bit-Debug\bin\Debug\reader\* /e /h /k
copy ..\src\ffmpeg\lib\avcodec-53.dll 		..\..\Aries-Desktop-MSVC2013-32bit-Debug\bin\Debug
copy ..\src\ffmpeg\lib\avdevice-53.dll 		..\..\Aries-Desktop-MSVC2013-32bit-Debug\bin\Debug
copy ..\src\ffmpeg\lib\avfilter-2.dll 		..\..\Aries-Desktop-MSVC2013-32bit-Debug\bin\Debug
copy ..\src\ffmpeg\lib\avformat-53.dll 		..\..\Aries-Desktop-MSVC2013-32bit-Debug\bin\Debug
copy ..\src\ffmpeg\lib\avutil-51.dll 		..\..\Aries-Desktop-MSVC2013-32bit-Debug\bin\Debug
copy ..\src\ffmpeg\lib\postproc-51.dll 		..\..\Aries-Desktop-MSVC2013-32bit-Debug\bin\Debug
copy ..\src\ffmpeg\lib\swscale-2.dll 		..\..\Aries-Desktop-MSVC2013-32bit-Debug\bin\Debug

