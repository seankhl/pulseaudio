/*
 *
 *  BlueZ - Bluetooth protocol stack for Linux
 *
 *  Copyright (C) 2006-2010  Nokia Corporation
 *  Copyright (C) 2004-2010  Marcel Holtmann <marcel@holtmann.org>
 *
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, see <http://www.gnu.org/licenses/>.
 *
 */

#define A2DP_CODEC_SBC			0x00
#define A2DP_CODEC_MPEG12		0x01
#define A2DP_CODEC_MPEG24		0x02
#define A2DP_CODEC_ATRAC		0x03
#define A2DP_CODEC_VENDOR		0xFF

/* customized 16-bit vendor extension */
#define A2DP_CODEC_VENDOR_APTX		0x4FFF
#define A2DP_CODEC_VENDOR_LDAC		0x2DFF

#define SBC_SAMPLING_FREQ_16000		(1 << 3)
#define SBC_SAMPLING_FREQ_32000		(1 << 2)
#define SBC_SAMPLING_FREQ_44100		(1 << 1)
#define SBC_SAMPLING_FREQ_48000		1

#define SBC_CHANNEL_MODE_MONO			(1 << 3)
#define SBC_CHANNEL_MODE_DUAL_CHANNEL	(1 << 2)
#define SBC_CHANNEL_MODE_STEREO			(1 << 1)
#define SBC_CHANNEL_MODE_JOINT_STEREO	1

#define SBC_BLOCK_LENGTH_4		(1 << 3)
#define SBC_BLOCK_LENGTH_8		(1 << 2)
#define SBC_BLOCK_LENGTH_12		(1 << 1)
#define SBC_BLOCK_LENGTH_16		1

#define SBC_SUBBANDS_4			(1 << 1)
#define SBC_SUBBANDS_8			1

#define SBC_ALLOCATION_SNR		(1 << 1)
#define SBC_ALLOCATION_LOUDNESS	1

#define APTX_VENDOR_ID			0x0000004f
#define APTX_CODEC_ID			0x0001

#define APTX_CHANNEL_MODE_MONO			0x08
#define APTX_CHANNEL_MODE_DUAL_CHANNEL	0x04
#define APTX_CHANNEL_MODE_STEREO		0x02
#define APTX_CHANNEL_MODE_JOINT_STEREO	0x01

#define APTX_SAMPLING_FREQ_16000		0x08
#define APTX_SAMPLING_FREQ_32000		0x04
#define APTX_SAMPLING_FREQ_44100		0x02
#define APTX_SAMPLING_FREQ_48000		0x01

#define MPEG_CHANNEL_MODE_MONO			(1 << 3)
#define MPEG_CHANNEL_MODE_DUAL_CHANNEL	(1 << 2)
#define MPEG_CHANNEL_MODE_STEREO		(1 << 1)
#define MPEG_CHANNEL_MODE_JOINT_STEREO	1

#define MPEG_LAYER_MP1			(1 << 2)
#define MPEG_LAYER_MP2			(1 << 1)
#define MPEG_LAYER_MP3			1

#define MPEG_SAMPLING_FREQ_16000	(1 << 5)
#define MPEG_SAMPLING_FREQ_22050	(1 << 4)
#define MPEG_SAMPLING_FREQ_24000	(1 << 3)
#define MPEG_SAMPLING_FREQ_32000	(1 << 2)
#define MPEG_SAMPLING_FREQ_44100	(1 << 1)
#define MPEG_SAMPLING_FREQ_48000	1

#define MAX_BITPOOL 64
#define MIN_BITPOOL 2

#if __BYTE_ORDER == __LITTLE_ENDIAN

typedef struct {
	uint8_t channel_mode:4;
	uint8_t frequency:4;
	uint8_t allocation_method:2;
	uint8_t subbands:2;
	uint8_t block_length:4;
	uint8_t min_bitpool;
	uint8_t max_bitpool;
} __attribute__ ((packed)) a2dp_sbc_t;

typedef struct {
	uint32_t vendor_id;
	uint16_t codec_id;
} __attribute__ ((packed)) a2dp_vendor_codec_t;
typedef struct {
	a2dp_vendor_codec_t info;
	uint8_t channel_mode:4;
	uint8_t frequency:4;
} __attribute__ ((packed)) a2dp_aptx_t;

typedef struct {
	uint8_t channel_mode:4;
	uint8_t crc:1;
	uint8_t layer:3;
	uint8_t frequency:6;
	uint8_t mpf:1;
	uint8_t rfa:1;
	uint16_t bitrate;
} __attribute__ ((packed)) a2dp_mpeg_t;

#elif __BYTE_ORDER == __BIG_ENDIAN

typedef struct {
	uint8_t frequency:4;
	uint8_t channel_mode:4;
	uint8_t block_length:4;
	uint8_t subbands:2;
	uint8_t allocation_method:2;
	uint8_t min_bitpool;
	uint8_t max_bitpool;
} __attribute__ ((packed)) a2dp_sbc_t;

typedef struct {
	a2dp_vendor_codec_t info;
	uint8_t frequency:4;
	uint8_t channel_mode:4;
} __attribute__ ((packed)) a2dp_aptx_t;

typedef struct {
	uint8_t layer:3;
	uint8_t crc:1;
	uint8_t channel_mode:4;
	uint8_t rfa:1;
	uint8_t mpf:1;
	uint8_t frequency:6;
	uint16_t bitrate;
} __attribute__ ((packed)) a2dp_mpeg_t;

#else
#error "Unknown byte order"
#endif
