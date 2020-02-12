/*
 * FpImageDevice - An image based fingerprint reader device
 * Copyright (C) 2019 Benjamin Berg <bberg@redhat.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#pragma once

#include "fpi-image-device.h"

#define IMG_ENROLL_STAGES 5

typedef struct
{
  FpiImageDeviceState state;
  gboolean            active;
  gboolean            cancelling;

  gboolean            enroll_await_on_pending;
  gint                enroll_stage;

  guint               pending_activation_timeout_id;
  gboolean            pending_activation_timeout_waiting_finger_off;

  gint                bz3_threshold;
} FpImageDevicePrivate;


void fpi_image_device_activate (FpImageDevice *image_device);
void fpi_image_device_deactivate (FpImageDevice *image_device);
