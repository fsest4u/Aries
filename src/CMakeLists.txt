########################################################
#  
#  This is a CMake configuration file.
#  To use it you need CMake which can be 
#  downloaded from here: 
#    http://www.cmake.org/cmake/resources/software.html
#
#########################################################

cmake_minimum_required( VERSION 3.0.0 ) 

project( Aries )

#########################################################

# Qt5 packages minimum version 5.4
find_package(Qt5 5.4 COMPONENTS Core Network Svg WebKit WebKitWidgets Widgets Xml XmlPatterns Concurrent PrintSupport LinguistTools)
set(CMAKE_AUTOMOC ON)

set( MAIN_FILES
	main.cpp
)

set( MAINUI_FILES 
	mainUI/MainWindow.h
	mainUI/MainWindow.cpp
    mainUI/cio.h
    mainUI/cio.cpp
)

set( MISC_FILES 
    misc/SettingData.h
    misc/SettingData.cpp
)

set( FFMPEG_FILES
    ffmpeg/include/libavcodec/avcodec.h
    ffmpeg/include/libavcodec/avfft.h
    ffmpeg/include/libavcodec/dxva2.h
    ffmpeg/include/libavcodec/opt.h
    ffmpeg/include/libavcodec/vaapi.h
    ffmpeg/include/libavcodec/vdpau.h
    ffmpeg/include/libavcodec/version.h
    ffmpeg/include/libavcodec/xvmc.h
    ffmpeg/include/libavdevice/avdevice.h
    ffmpeg/include/libavformat/avformat.h
    ffmpeg/include/libavformat/avio.h
    ffmpeg/include/libavformat/version.h
    ffmpeg/include/libavutil/adler32.h
    ffmpeg/include/libavutil/aes.h
    ffmpeg/include/libavutil/attributes.h
    ffmpeg/include/libavutil/audioconvert.h
    ffmpeg/include/libavutil/avassert.h
    ffmpeg/include/libavutil/avconfig.h
    ffmpeg/include/libavutil/avstring.h
    ffmpeg/include/libavutil/avutil.h
    ffmpeg/include/libavutil/base64.h
    ffmpeg/include/libavutil/bswap.h
    ffmpeg/include/libavutil/common.h
    ffmpeg/include/libavutil/cpu.h
    ffmpeg/include/libavutil/crc.h
    ffmpeg/include/libavutil/dict.h
    ffmpeg/include/libavutil/error.h
    ffmpeg/include/libavutil/fifo.h
    ffmpeg/include/libavutil/file.h
    ffmpeg/include/libavutil/imgutils.h
    ffmpeg/include/libavutil/intfloat_readwrite.h
    ffmpeg/include/libavutil/intreadwrite.h
    ffmpeg/include/libavutil/lfg.h
    ffmpeg/include/libavutil/log.h
    ffmpeg/include/libavutil/lzo.h
    ffmpeg/include/libavutil/mathematics.h
    ffmpeg/include/libavutil/md5.h
    ffmpeg/include/libavutil/mem.h
    ffmpeg/include/libavutil/opt.h
    ffmpeg/include/libavutil/parseutils.h
    ffmpeg/include/libavutil/pixdesc.h
    ffmpeg/include/libavutil/pixfmt.h
    ffmpeg/include/libavutil/random_seed.h
    ffmpeg/include/libavutil/rational.h
    ffmpeg/include/libavutil/samplefmt.h
    ffmpeg/include/libavutil/sha.h   
    ffmpeg/include/libswscale/swscale.h
)

set ( FFMPEGQT_FILES
    ffmpegQT/ffmpeg.h
    ffmpegQT/QVideoDecoder.h
    ffmpegQT/QVideoDecoder.cpp
    ffmpegQT/QVideoEncoder.h
    ffmpegQT/QVideoEncoder.cpp)

set( UI_FILES
	formFiles/MainWindow.ui
)

set( QRC_FILES
	resFiles/resources.qrc
)

set( RAW_SOURCES ${MAIN_FILES} ${MAINUI_FILES} ${MISC_FILES} ${FFMPEG_FILES} ${FFMPEGQT_FILES})

set( FFMEPG_INCLUDE_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/ffmpeg/include
)

set ( FFMPEG_LIB_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/ffmpeg/lib/avcodec.lib
    ${CMAKE_CURRENT_SOURCE_DIR}/ffmpeg/lib/avdevice.lib
    ${CMAKE_CURRENT_SOURCE_DIR}/ffmpeg/lib/avformat.lib
    ${CMAKE_CURRENT_SOURCE_DIR}/ffmpeg/lib/avutil.lib
    ${CMAKE_CURRENT_SOURCE_DIR}/ffmpeg/lib/swscale.lib
)

#########################################################

# Runs UIC on specified files
qt5_wrap_ui( UI_FILES_H ${UI_FILES} )
# Runs RCC on specified files
qt5_add_resources( QRC_FILES_CPP ${QRC_FILES} )
# Runs lrelease on the specified files
qt5_add_translation( QM_FILES ${TS_FILES} )

# Define the Aries version string for use in source files
# set_source_files_properties( Misc/Utility.cpp PROPERTIES COMPILE_DEFINITIONS ARIES_FULL_VERSION="${ARIES_FULL_VERSION}" )
# set_source_files_properties( Dialogs/About.cpp PROPERTIES COMPILE_DEFINITIONS ARIES_FULL_VERSION="${ARIES_FULL_VERSION}" )
# set_property( SOURCE Dialogs/About.cpp APPEND PROPERTY COMPILE_DEFINITIONS ARIES_FULL_VERSION="${ARIES_FULL_VERSION}" ARIES_CODE_NAME="${ARIES_CODE_NAME}" )

#########################################################

# Adds folders for Visual Studio solution explorer (and for Xcode explorer)
source_group( "Form Files"              FILES ${UI_FILES} )
source_group( "Resource Files"          FILES ${QRC_FILES} )
source_group( "Misc"                    FILES ${MISC_FILES} )
source_group( "Main UI"                 FILES ${MAINUI_FILES} )
source_group( "Main Files"              FILES ${MAIN_FILES} )
source_group( "FFMpeg Files"            FILES ${FFMPEG_FILES} )
source_group( "FFMpegQT Files"          FILES ${FFMPEGQT_FILES} )

#########################################################

set( ALL_SOURCES ${RAW_SOURCES} ${UI_FILES_H} ${QRC_FILES_CPP} ${QM_FILES} )

#########################################################

# We need to pick up the ui*.h files,
# and the headers for the linked-to libraries.
# The directories are in reverse order because we're using before to
# put our include dirs before any system ones.
include_directories( BEFORE
                     ${CMAKE_CURRENT_SOURCE_DIR}
                     ${CMAKE_CURRENT_BINARY_DIR}
                     ${FFMEPG_INCLUDE_FILES} )

#########################################################

add_executable( ${PROJECT_NAME} WIN32 ${ALL_SOURCES} )

if (MSVC)
    set(QT_MAIN Qt5::WinMain)
endif()

target_link_libraries( ${PROJECT_NAME} ${QT_MAIN} ${FFMPEG_LIB_FILES} )
qt5_use_modules(${PROJECT_NAME} Widgets Xml XmlPatterns PrintSupport Svg WebKit WebKitWidgets Network Concurrent Multimedia)

#########################################################

# Speed up stirng building
add_definitions( -DQT_USE_FAST_CONCATENATION )
add_definitions( -DQT_USE_FAST_OPERATOR_PLUS )

#########################################################

# "Link time code generation" flags for MSVC
if( MSVC )
    add_definitions( /DUNICODE /D_UNICODE /DHAVE_ROUND )
    # The /Zc:wchar_t- flag can't go into add_definitions
    # because the RC compiler picks it up too and it provokes a name clash
    set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Zc:wchar_t- /MP")
    set( CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /Oi /GL" ) 
    set( CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} /LTCG" )

# "Print all warnings" flag for GCC
elseif( CMAKE_COMPILER_IS_GNUCXX )
    add_definitions( -Wall )
endif()

#########################################################
