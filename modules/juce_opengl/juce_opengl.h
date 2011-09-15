/*
  ==============================================================================

   This file is part of the JUCE library - "Jules' Utility Class Extensions"
   Copyright 2004-11 by Raw Material Software Ltd.

  ------------------------------------------------------------------------------

   JUCE can be redistributed and/or modified under the terms of the GNU General
   Public License (Version 2), as published by the Free Software Foundation.
   A copy of the license is included in the JUCE distribution, or can be found
   online at www.gnu.org/licenses.

   JUCE is distributed in the hope that it will be useful, but WITHOUT ANY
   WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
   A PARTICULAR PURPOSE.  See the GNU General Public License for more details.

  ------------------------------------------------------------------------------

   To release a closed-source product which uses JUCE, commercial licenses are
   available: visit www.rawmaterialsoftware.com/juce for more information.

  ==============================================================================
*/

#ifndef __JUCE_OPENGL_JUCEHEADER__
#define __JUCE_OPENGL_JUCEHEADER__

#include "../juce_gui_extra/juce_gui_extra.h"

#undef JUCE_OPENGL

#if ! JUCE_ANDROID
 #define JUCE_OPENGL 1
#endif

#if JUCE_IOS || JUCE_ANDROID
 #define JUCE_OPENGL_ES 1
#endif

#if JUCE_WINDOWS
 #ifndef APIENTRY
  #define APIENTRY __stdcall
  #define CLEAR_TEMP_APIENTRY 1
 #endif
 #ifndef WINGDIAPI
  #define WINGDIAPI __declspec(dllimport)
  #define CLEAR_TEMP_WINGDIAPI 1
 #endif
 #include <gl/GL.h>
 #ifdef CLEAR_TEMP_WINGDIAPI
  #undef WINGDIAPI
  #undef CLEAR_TEMP_WINGDIAPI
 #endif
 #ifdef CLEAR_TEMP_APIENTRY
  #undef APIENTRY
  #undef CLEAR_TEMP_APIENTRY
 #endif
#elif JUCE_LINUX
 #include <GL/gl.h>
 #undef KeyPress
#elif JUCE_IOS
 #include <OpenGLES/ES1/gl.h>
 #include <OpenGLES/ES1/glext.h>
#elif JUCE_MAC
 #include <OpenGL/gl.h>
 #include "OpenGL/glext.h"
#endif

#ifndef GL_BGRA_EXT
 #define GL_BGRA_EXT 0x80e1
#endif

#ifndef GL_CLAMP_TO_EDGE
 #define GL_CLAMP_TO_EDGE 0x812f
#endif

#ifndef GL_DEPTH_COMPONENT16
 #define GL_DEPTH_COMPONENT16 0x81a5
#endif

//=============================================================================
BEGIN_JUCE_NAMESPACE

// START_AUTOINCLUDE opengl
#ifndef __JUCE_OPENGLCOMPONENT_JUCEHEADER__
 #include "opengl/juce_OpenGLComponent.h"
#endif
#ifndef __JUCE_OPENGLCONTEXT_JUCEHEADER__
 #include "opengl/juce_OpenGLContext.h"
#endif
#ifndef __JUCE_OPENGLFRAMEBUFFER_JUCEHEADER__
 #include "opengl/juce_OpenGLFrameBuffer.h"
#endif
#ifndef __JUCE_OPENGLHELPERS_JUCEHEADER__
 #include "opengl/juce_OpenGLHelpers.h"
#endif
#ifndef __JUCE_OPENGLPIXELFORMAT_JUCEHEADER__
 #include "opengl/juce_OpenGLPixelFormat.h"
#endif
#ifndef __JUCE_OPENGLTEXTURE_JUCEHEADER__
 #include "opengl/juce_OpenGLTexture.h"
#endif
// END_AUTOINCLUDE

END_JUCE_NAMESPACE

#endif   // __JUCE_OPENGL_JUCEHEADER__