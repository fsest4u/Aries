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

set( FFMPEG_AVCODEC_FILES
    ffmpeg341/include/libavcodec/avcodec.h
    ffmpeg341/include/libavcodec/avdct.h
    ffmpeg341/include/libavcodec/avfft.h
    ffmpeg341/include/libavcodec/d3d11va.h
    ffmpeg341/include/libavcodec/dirac.h
    ffmpeg341/include/libavcodec/dv_profile.h
    ffmpeg341/include/libavcodec/dxva2.h
    ffmpeg341/include/libavcodec/jni.h
    ffmpeg341/include/libavcodec/mediacodec.h
    ffmpeg341/include/libavcodec/qsv.h
    ffmpeg341/include/libavcodec/vaapi.h
    ffmpeg341/include/libavcodec/vda.h
    ffmpeg341/include/libavcodec/vdpau.h
    ffmpeg341/include/libavcodec/version.h
    ffmpeg341/include/libavcodec/videotoolbox.h
    ffmpeg341/include/libavcodec/vorbis_parser.h
    ffmpeg341/include/libavcodec/xvmc.h    
)

set( FFMPEG_AVDEVICE_FILES
    ffmpeg341/include/libavdevice/avdevice.h
    ffmpeg341/include/libavdevice/version.h
)

set( FFMPEG_AVFILTER_FILES
    ffmpeg341/include/libavfilter/avfilter.h
    ffmpeg341/include/libavfilter/avfiltergraph.h
    ffmpeg341/include/libavfilter/buffersink.h
    ffmpeg341/include/libavfilter/buffersrc.h
    ffmpeg341/include/libavfilter/version.h    
)

set( FFMPEG_AVFORMAT_FILES
    ffmpeg341/include/libavformat/avformat.h
    ffmpeg341/include/libavformat/avio.h
    ffmpeg341/include/libavformat/version.h
)

set( FFMPEG_AVUTIL_FILES
    ffmpeg341/include/libavutil/adler32.h
    ffmpeg341/include/libavutil/aes.h
    ffmpeg341/include/libavutil/aes_ctr.h
    ffmpeg341/include/libavutil/attributes.h
    ffmpeg341/include/libavutil/audio_fifo.h
    ffmpeg341/include/libavutil/avassert.h
    ffmpeg341/include/libavutil/avconfig.h
    ffmpeg341/include/libavutil/avstring.h
    ffmpeg341/include/libavutil/avutil.h
    ffmpeg341/include/libavutil/base64.h
    ffmpeg341/include/libavutil/blowfish.h
    ffmpeg341/include/libavutil/bprint.h
    ffmpeg341/include/libavutil/bswap.h
    ffmpeg341/include/libavutil/buffer.h
    ffmpeg341/include/libavutil/camellia.h
    ffmpeg341/include/libavutil/cast5.h
    ffmpeg341/include/libavutil/channel_layout.h
    ffmpeg341/include/libavutil/common.h
    ffmpeg341/include/libavutil/cpu.h
    ffmpeg341/include/libavutil/crc.h
    ffmpeg341/include/libavutil/des.h
    ffmpeg341/include/libavutil/dict.h
    ffmpeg341/include/libavutil/display.h
    ffmpeg341/include/libavutil/downmix_info.h
    ffmpeg341/include/libavutil/error.h
    ffmpeg341/include/libavutil/eval.h
    ffmpeg341/include/libavutil/ffversion.h
    ffmpeg341/include/libavutil/fifo.h
    ffmpeg341/include/libavutil/file.h
    ffmpeg341/include/libavutil/frame.h
    ffmpeg341/include/libavutil/hash.h
    ffmpeg341/include/libavutil/hmac.h
    ffmpeg341/include/libavutil/hwcontext.h
    ffmpeg341/include/libavutil/hwcontext_cuda.h
    ffmpeg341/include/libavutil/hwcontext_d3d11va.h
    ffmpeg341/include/libavutil/hwcontext_drm.h
    ffmpeg341/include/libavutil/hwcontext_dxva2.h
    ffmpeg341/include/libavutil/hwcontext_qsv.h
    ffmpeg341/include/libavutil/hwcontext_vaapi.h
    ffmpeg341/include/libavutil/hwcontext_vdpau.h
    ffmpeg341/include/libavutil/hwcontext_videotoolbox.h
    ffmpeg341/include/libavutil/imgutils.h
    ffmpeg341/include/libavutil/intfloat.h
    ffmpeg341/include/libavutil/intreadwrite.h
    ffmpeg341/include/libavutil/lfg.h
    ffmpeg341/include/libavutil/log.h
    ffmpeg341/include/libavutil/lzo.h
    ffmpeg341/include/libavutil/macros.h
    ffmpeg341/include/libavutil/mastering_display_metadata.h
    ffmpeg341/include/libavutil/mathematics.h
    ffmpeg341/include/libavutil/md5.h
    ffmpeg341/include/libavutil/mem.h
    ffmpeg341/include/libavutil/motion_vector.h
    ffmpeg341/include/libavutil/murmur3.h
    ffmpeg341/include/libavutil/opt.h
    ffmpeg341/include/libavutil/parseutils.h
    ffmpeg341/include/libavutil/pixdesc.h
    ffmpeg341/include/libavutil/pixelutils.h
    ffmpeg341/include/libavutil/pixfmt.h
    ffmpeg341/include/libavutil/random_seed.h
    ffmpeg341/include/libavutil/rational.h
    ffmpeg341/include/libavutil/rc4.h
    ffmpeg341/include/libavutil/replaygain.h
    ffmpeg341/include/libavutil/ripemd.h
    ffmpeg341/include/libavutil/samplefmt.h
    ffmpeg341/include/libavutil/sha.h
    ffmpeg341/include/libavutil/sha512.h
    ffmpeg341/include/libavutil/spherical.h
    ffmpeg341/include/libavutil/stereo3d.h
    ffmpeg341/include/libavutil/tea.h
    ffmpeg341/include/libavutil/threadmessage.h
    ffmpeg341/include/libavutil/time.h
    ffmpeg341/include/libavutil/timecode.h
    ffmpeg341/include/libavutil/timestamp.h
    ffmpeg341/include/libavutil/tree.h
    ffmpeg341/include/libavutil/twofish.h
    ffmpeg341/include/libavutil/version.h
    ffmpeg341/include/libavutil/xtea.h
)

set( FFMPEG_POSTPROC_FILES
    ffmpeg341/include/libpostproc/postprocess.h
    ffmpeg341/include/libavutil/version.h
)

set( FFMPEG_SWRESAMPLE_FILES
    ffmpeg341/include/libswresample/swresample.h
    ffmpeg341/include/libswresample/version.h
)

set( FFMPEG_SWSCALE_FILES
    ffmpeg341/include/libswscale/swscale.h
    ffmpeg341/include/libswscale/version.h
)

set( FFMPEGQT_FILES
    ffmpegQT341/ffmpeg.h
    ffmpegQT341/QVideoDecoder.h
    ffmpegQT341/QVideoDecoder.cpp
)

set( SDL2_FILES
    SDL207/include/begin_code.h
    SDL207/include/close_code.h
    SDL207/include/SDL.h
    SDL207/include/SDL_assert.h
    SDL207/include/SDL_atomic.h
    SDL207/include/SDL_audio.h
    SDL207/include/SDL_bits.h
    SDL207/include/SDL_blendmode.h
    SDL207/include/SDL_clipboard.h
    SDL207/include/SDL_config.h
    SDL207/include/SDL_config_android.h
    SDL207/include/SDL_config_iphoneos.h
    SDL207/include/SDL_config_macosx.h
    SDL207/include/SDL_config_minimal.h
    SDL207/include/SDL_config_pandora.h
    SDL207/include/SDL_config_psp.h
    SDL207/include/SDL_config_windows.h
    SDL207/include/SDL_config_winrt.h
    SDL207/include/SDL_config_wiz.h
    SDL207/include/SDL_copying.h
    SDL207/include/SDL_cpuinfo.h
    SDL207/include/SDL_egl.h
    SDL207/include/SDL_endian.h
    SDL207/include/SDL_error.h
    SDL207/include/SDL_events.h
    SDL207/include/SDL_filesystem.h
    SDL207/include/SDL_gamecontroller.h
    SDL207/include/SDL_gesture.h
    SDL207/include/SDL_haptic.h
    SDL207/include/SDL_hints.h
    SDL207/include/SDL_joystick.h
    SDL207/include/SDL_keyboard.h
    SDL207/include/SDL_keycode.h
    SDL207/include/SDL_loadso.h
    SDL207/include/SDL_log.h
    SDL207/include/SDL_main.h
    SDL207/include/SDL_messagebox.h
    SDL207/include/SDL_mouse.h
    SDL207/include/SDL_mutex.h
    SDL207/include/SDL_name.h
    SDL207/include/SDL_opengl.h
    SDL207/include/SDL_opengles.h
    SDL207/include/SDL_opengles2.h
    SDL207/include/SDL_opengles2_gl2.h
    SDL207/include/SDL_opengles2_gl2ext.h
    SDL207/include/SDL_opengles2_gl2platform.h
    SDL207/include/SDL_opengles2_khrplatform.h
    SDL207/include/SDL_opengl_glext.h
    SDL207/include/SDL_pixels.h
    SDL207/include/SDL_platform.h
    SDL207/include/SDL_power.h
    SDL207/include/SDL_quit.h
    SDL207/include/SDL_rect.h
    SDL207/include/SDL_render.h
    SDL207/include/SDL_revision.h
    SDL207/include/SDL_rwops.h
    SDL207/include/SDL_scancode.h
    SDL207/include/SDL_shape.h
    SDL207/include/SDL_stdinc.h
    SDL207/include/SDL_surface.h
    SDL207/include/SDL_system.h
    SDL207/include/SDL_syswm.h
    SDL207/include/SDL_test.h
    SDL207/include/SDL_test_assert.h
    SDL207/include/SDL_test_common.h
    SDL207/include/SDL_test_compare.h
    SDL207/include/SDL_test_crc32.h
    SDL207/include/SDL_test_font.h
    SDL207/include/SDL_test_fuzzer.h
    SDL207/include/SDL_test_harness.h
    SDL207/include/SDL_test_images.h
    SDL207/include/SDL_test_log.h
    SDL207/include/SDL_test_md5.h
    SDL207/include/SDL_test_memory.h
    SDL207/include/SDL_test_random.h
    SDL207/include/SDL_thread.h
    SDL207/include/SDL_timer.h
    SDL207/include/SDL_touch.h
    SDL207/include/SDL_types.h
    SDL207/include/SDL_version.h
    SDL207/include/SDL_video.h
    SDL207/include/SDL_vulkan.h
)

set( UI_FILES
	formFiles/MainWindow.ui
)

set( QRC_FILES
	resFiles/resources.qrc
)

set( RAW_SOURCES ${MAIN_FILES} ${MAINUI_FILES} ${MISC_FILES} ${FFMPEG_AVCODEC_FILES} ${FFMPEG_AVDEVICE_FILES} ${FFMPEG_AVFILTER_FILES} ${FFMPEG_AVFORMAT_FILES} ${FFMPEG_AVUTIL_FILES} ${FFMPEG_POSTPROC_FILES} ${FFMPEG_SWRESAMPLE_FILES} ${FFMPEG_SWSCALE_FILES} ${FFMPEGQT_FILES} ${SDL2_FILES} )

set( FFMEPG_INCLUDE_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/ffmpeg341/include
)

set( FFMPEG_LIB_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/ffmpeg341/lib/avcodec.lib
    ${CMAKE_CURRENT_SOURCE_DIR}/ffmpeg341/lib/avdevice.lib
    ${CMAKE_CURRENT_SOURCE_DIR}/ffmpeg341/lib/avfilter.lib
    ${CMAKE_CURRENT_SOURCE_DIR}/ffmpeg341/lib/avformat.lib
    ${CMAKE_CURRENT_SOURCE_DIR}/ffmpeg341/lib/avutil.lib
    ${CMAKE_CURRENT_SOURCE_DIR}/ffmpeg341/lib/postproc.lib
    ${CMAKE_CURRENT_SOURCE_DIR}/ffmpeg341/lib/swresample.lib    
    ${CMAKE_CURRENT_SOURCE_DIR}/ffmpeg341/lib/swscale.lib
)

set( SDL2_INCLUDE_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/SDL207/include
)

set( SDL2_LIB_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/SDL207/lib/SDL2.lib
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
source_group( "FFMpeg AVCodec Files"    FILES ${FFMPEG_AVCODEC_FILES} )
source_group( "FFMpeg AVDevice Files"   FILES ${FFMPEG_AVDEVICE_FILES} )
source_group( "FFMpeg AVFilter Files"   FILES ${FFMPEG_AVFILTER_FILES} )
source_group( "FFMpeg AVFormat Files"   FILES ${FFMPEG_AVFORMAT_FILES} )
source_group( "FFMpeg AVUtil Files"     FILES ${FFMPEG_AVUTIL_FILES} )
source_group( "FFMpeg Postproc Files"   FILES ${FFMPEG_POSTPROC_FILES} )
source_group( "FFMpeg SWRESample Files" FILES ${FFMPEG_SWRESAMPLE_FILES} )
source_group( "FFMpeg SWScale Files"    FILES ${FFMPEG_SWSCALE_FILES} )
source_group( "FFMpegQT Files"          FILES ${FFMPEGQT_FILES} )
source_group( "SDL2 Files"              FILES ${SDL2_FILES} )

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
                     ${FFMEPG_INCLUDE_FILES}
                     ${SDL2_INCLUDE_FILES} )

#########################################################

add_executable( ${PROJECT_NAME} WIN32 ${ALL_SOURCES} )

if (MSVC)
    set(QT_MAIN Qt5::WinMain)
endif()

target_link_libraries( ${PROJECT_NAME} ${QT_MAIN} ${FFMPEG_LIB_FILES} ${SDL2_LIB_FILES} )
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
