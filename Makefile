#******************************************************************************
# Makefile                                                 Unsubquirrel project
#******************************************************************************
#
#  File Description:
#
#    Makefile for unsubsquirrel
#
#
#
#
#
#
#
#
#******************************************************************************
#  (C) 2019 Christophe de Dinechin <christophe@dinechin.org>
#  This software is licensed under the GNU General Public License v3
#******************************************************************************
#  This file is part of Unsubquirrel.
#
#  Unsubquirrel is free software: you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation, either version 3 of the License, or
#  (at your option) any later version.
#
#  Unsubquirrel is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#
#  You should have received a copy of the GNU General Public License
#  along with Unsubquirrel.  If not, see <https://www.gnu.org/licenses/>.
#******************************************************************************

SOURCES=unsubsquirrel.c
PRODUCTS=unsubsquirrel.exe
PRODUCTS_VERSION=$(PACKAGE_VERSION)
CONFIG=
MANPAGES=$(wildcard man/man3/*.3 man/man1/*.1)

# For pkg-config generation
PACKAGE_NAME=unsubsquirrel
PACKAGE_VERSION=0.0.1
PACKAGE_DESCRIPTION=A program that teaches you how to unsubquirrel
PACKAGE_URL="http://github.com/c3d/unsubsquirrel"
PACKAGE_REQUIRES=
PACKAGE_BUGS=christophe@dinechin.org

TESTS=  product
TEST_ARGS="You have not been very successful at it, have you?"

MIQ=make-it-quick/
include $(MIQ)rules.mk

$(MIQ)rules.mk:
	git submodule update --init --recursive
