/*
 * This binary extracts the ramdisk from a Sony ELF or ANDROID boot or
 * recovery image, gunzips it, checks to make sure that it is not a
 * stock recovery ramdisk, and then places it in the destination.
 * The goal is to use the FOTA partition to store a recovery image
 * and extract the ramdisk to be used during boot on Sony devices that
 * typically have a recovery-in-boot setup due to Sony disabling the
 * ability to boot the FOTA partition on unlocked devices. This binary
 * allows the recovery ramdisk to be separate from the boot partition
 * so that users can decide what recovery they want to have instead of
 * being stuck with whatever recovery their kernel or ROM maker decided
 * to include in the boot image.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 *
 * The code was written from scratch by Dees_Troy dees_troy at
 * yahoo
 *
 * Copyright (c) 2013
 * Copyright (C) 2016 The CyanogenMod Project
 * Copyright (C) 2018 The OmniRom Project
 */

#ifndef __UNCOMPRESS_H__
#define __UNCOMPRESS_H__

#define MEMORY_BUFFER_SIZE (const size_t)40*1024*1024 // Max size of uncompressed
                                                   // ramdisk (40 MB)

typedef char* byte_p;

size_t uncompress_gzip_memory(const byte_p compressed_data,
		const size_t compressed_data_size, const byte_p uncompressed_data,
		const size_t uncompressed_max_size);

size_t uncompress_memory(byte_p uncompressed_buffer, byte_p buffer, unsigned long file_size);

#endif // __UNCOMPRESS_H__
