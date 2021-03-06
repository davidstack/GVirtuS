/*
 * gVirtuS -- A GPGPU transparent virtualization component.
 *
 * Copyright (C) 2009-2010  The University of Napoli Parthenope at Naples.
 *
 * This file is part of gVirtuS.
 *
 * gVirtuS is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * gVirtuS is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with gVirtuS; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * Written by: Giuseppe Coviello <giuseppe.coviello@uniparthenope.it>,
 *             Department of Applied Science
 */

/**
 * @file   Handler.h
 * @author Giuseppe Coviello <giuseppe.coviello@uniparthenope.it>
 * @date   Wed Jan 12 10:01:58 2011
 *
 * @brief
 *
 *
 */

#pragma once

#include <gvirtus/communicators/Result.h>
#include <memory>
#include "log4cplus/configurator.h"
#include "log4cplus/logger.h"
#include "log4cplus/loggingmacros.h"

namespace gvirtus::backend {
class Handler {
 protected:
  using create_t = std::shared_ptr<Handler>();

 public:
  virtual bool CanExecute(std::string routine) = 0;
  virtual std::shared_ptr<communicators::Result> Execute(
      std::string routine,
      std::shared_ptr<communicators::Buffer> input_buffer) = 0;

 private:
  log4cplus::Logger logger;
};
}  // namespace gvirtus::backend
