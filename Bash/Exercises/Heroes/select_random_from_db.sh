# DESCRIPTION : select som random name from heroes_db.csv
# and save it in a file called heroes_instack.txt
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
awk -F , '{print $2}' heroes_db.csv | sed -n 100,105p > heroes_instack.txt
awk -F , '{print $2}' heroes_db.csv | sed -n 200,105p >> heroes_instack.txt
awk -F , '{print $2}' heroes_db.csv | sed -n 300,305p >> heroes_instack.txt
awk -F , '{print $2}' heroes_db.csv | sed -n 400,405p >> heroes_instack.txt
awk -F , '{print $2}' heroes_db.csv | sed -n 500,505p >> heroes_instack.txt
