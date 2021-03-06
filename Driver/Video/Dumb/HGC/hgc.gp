##############################################################################
#
#	Copyright (c) GeoWorks 1989 -- All Rights Reserved
#
# PROJECT:	PC GEOS
# MODULE:	Kernel
# FILE:		hgc.gp
#
# AUTHOR:	Adam, 10/89
#
#
# Parameters file for: hgc.geo
#
#	$Id: hgc.gp,v 1.1 97/04/18 11:42:35 newdeal Exp $
#
##############################################################################
#
#
# Specify permanent name first
#
name	hgc.drvr
#
# Specify geode type
#
type	driver, single, system
#
# Import kernel routine definitions
#
library	geos
#
# Desktop-related things
#
longname	"Hercules Monochrome Driver"
tokenchars	"VIDD"
tokenid		0
#
# declare our extended info block specially
#
resource VideoDevices	lmem, shared, read-only, conforming
