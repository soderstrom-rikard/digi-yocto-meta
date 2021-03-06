# Copyright (C) 2013 Digi International.

DESCRIPTION = "Stunnel is a program that allows you to encrypt \
arbitrary TCP connections inside SSL"
SECTION = "console/network"
DEPENDS = "openssl"
HOMEPAGE = "http://www.stunnel.org"
LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://COPYING;md5=f41ebed8571077706fee0b860c4d6666"

INC_PR = "r0"

S = "${WORKDIR}/stunnel-${PV}"

inherit autotools update-rc.d

INITSCRIPT_NAME = "stunnel"
INITSCRIPT_PARAMS = "defaults"

EXTRA_OECONF = "--with-ssl=${STAGING_LIBDIR}/.. \
		--with-random=/dev/urandom \
		--with-ptmx \
		--without-ptc"

do_install() {
	autotools_do_install
	install -d ${D}${sysconfdir}/stunnel ${D}${sysconfdir}/init.d
	install -m 755 ${WORKDIR}/init ${D}${sysconfdir}/init.d/stunnel
	install -m 644 ${WORKDIR}/stunnel.conf ${D}${sysconfdir}/stunnel
}
