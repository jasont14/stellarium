/*
 * Stellarium
 * Copyright (C) 2002 Fabien Ch�reau
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */

#ifndef _S_TEXTURE_H_
#define _S_TEXTURE_H_

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#ifdef MACOSX
# include <OpenGL/gl.h>
# include <OpenGL/glu.h>
#else
# include <GL/gl.h>
# include <GL/glu.h>
#endif

#define TEX_LOAD_TYPE_PNG_ALPHA 0
#define TEX_LOAD_TYPE_PNG_SOLID 1
#define TEX_LOAD_TYPE_PNG_BLEND3 2
#define TEX_LOAD_TYPE_PNG_REPEAT 3
#define TEX_LOAD_TYPE_PNG_SOLID_REPEAT 4

#include <string.h>

class s_texture
{
public:
    s_texture(const char * _textureName);
    s_texture(const char * _textureName, int _loadType);
    virtual ~s_texture();
    int load();
    void unload();
    int reload();
    unsigned int getID(void) const {return texID;}
	// Return the average texture luminance : 0 is black, 1 is white
	float get_average_luminance(void) const;
	static void set_texDir(char * _texDir) {strncpy(s_texture::texDir, _texDir, sizeof(texDir));}
	static void set_suffix(char * _suffix) {strncpy(s_texture::suffix, _suffix, sizeof(suffix));}
private:
    char * textureName;
    GLuint texID;
    int loadType;
    int loadType2;
	static char texDir[255];
	static char suffix[10];
};


#endif // _S_TEXTURE_H_
