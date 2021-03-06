# Copyright (C) 2013 Digi International.

PRINC := "${@int(PRINC) + 1}"
PR_append = "+${DISTRO}"

FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}/${MACHINE}/${PREFERRED_VERSION_linux-dey}:${THISDIR}/${PN}/${MACHINE}:"

SRC_URI += " \
    file://asound.inline_play.state \
    file://asound.inline.state \
    file://asound.micro_play.state \
    file://asound.micro.state \
    file://asound.play.state \
"

# The default 'asound.conf' config file is not valid for our platforms and
# according to <http://www.alsa-project.org/main/index.php/Asoundrc> is not
# required
do_install_append() {
	rm -f ${D}${sysconfdir}/asound.conf
	ln -sf asound.micro_play.state ${D}${localstatedir}/lib/alsa/asound.state
}
