# DESCRIPTION : print all heroes that start with a letter
# passed as parameter
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <https://www.gnu.org/licenses/>.
# 
# Copyright (c) 2019 by Gaetano Di Grazia, education.digrazia@gmail.com
# All rights reserved.

#!/bin/bash

startletter=$1

if [ $# -eq 0 ];
	then echo "Insert a parameter"
else
	grep -i -E "^$startletter" heroes.txt
fi
