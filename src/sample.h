#ifndef foosamplehfoo
#define foosamplehfoo

/* $Id$ */

/***
  This file is part of polypaudio.
 
  polypaudio is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published
  by the Free Software Foundation; either version 2 of the License,
  or (at your option) any later version.
 
  polypaudio is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
  General Public License for more details.
 
  You should have received a copy of the GNU General Public License
  along with polypaudio; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
  USA.
***/

#include <inttypes.h>
#include <sys/types.h>

enum pa_sample_format {
    PA_SAMPLE_U8,
    PA_SAMPLE_ALAW,
    PA_SAMPLE_ULAW,
    PA_SAMPLE_S16LE,
    PA_SAMPLE_S16BE,
    PA_SAMPLE_FLOAT32LE,
    PA_SAMPLE_FLOAT32BE,
    PA_SAMPLE_MAX
};

#ifdef WORDS_BIGENDIAN
#define PA_SAMPLE_S16NE PA_SAMPLE_S16BE
#define PA_SAMPLE_FLOAT32NE PA_SAMPLE_FLOAT32BE
#else
#define PA_SAMPLE_S16NE PA_SAMPLE_S16LE
#define PA_SAMPLE_FLOAT32NE PA_SAMPLE_FLOAT32LE
#endif
#define PA_SAMPLE_FLOAT32 PA_SAMPLE_FLOAT32NE

struct pa_sample_spec {
    enum pa_sample_format format;
    uint32_t rate;
    uint8_t channels;
};

size_t pa_bytes_per_second(const struct pa_sample_spec *spec);
size_t pa_sample_size(const struct pa_sample_spec *spec);
uint32_t pa_samples_usec(size_t length, const struct pa_sample_spec *spec);
int pa_sample_spec_valid(const struct pa_sample_spec *spec);
int pa_sample_spec_equal(const struct pa_sample_spec*a, const struct pa_sample_spec*b);


#define PA_SAMPLE_SNPRINT_MAX_LENGTH 32
void pa_sample_snprint(char *s, size_t l, const struct pa_sample_spec *spec);

#endif
