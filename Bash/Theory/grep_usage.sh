# DESCRIPTION : grep usage
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

#INPUT 
grep "pattern" filename

#OUTPUT: 1, if filename.extension is specified
#"Pattern", if exists, blank otherwise

#OUTPUT: 2, if grep "pattern" *
#filename.extension: "pattern"

#SEARCH FOR STRING IN MANY FILES
grep "pattern" *

#CASE INSENSITIVE SEARCH
grep -i "pattern" filename

#FIND EXACTLY A PATTERN
grep -w "pattern" filename

#DISPLAY N LINES AFTER MATCH
grep -A 4 "pattern" filename

#DISPLAY N LINES BEFORE MATCH
grep -B 4 "pattern" filename

#DISPLAY N LINES AROUND MATCH
grep -C 4 "pattern" filename

#RECURSIVELY SEARCH
grep -r "pattern" filename

#INVERT SEARCHING
grep -v "pattern" filename

#COUNTING THE NUMBER OF MATCHES
grep -c "pattern" filename

#DISPLAY ONLY THE FILE NAME WITH MATCH THE GIVEN PATTERN
grep -l "pattern" filename

#DISPLAY THE POSITION OF MATCH IN THE LINE
grep -o -b "pattern" filename
#-o = match only string
#-b = show position

#DISPLAY THE LINE NUMBER OF THE GIVEN PATTERN IN THE FILE
grep -n "pattern" filename

#USE REGEX IN GREP
grep -E "regex" filename

# Regex command
# ? the item is matched 0 or 1 times
# * the item is matched 0 or n times
# + the item is matched 1 or n times
# . the item is matched 1 times
# {n} the items is matched exactly n times
# {n, } the item is matched n or more times
# {, m} the item is matched at most m times
# {n,m} the item is matched from n to m times
# $ the item is matched at the end of the pattern
# ^ the item is matched at the beginning of the pattern
# [A-Z] the item match one of this uppercase letter (A to Z)
# [a-z] the item match one of this lowercase letter (a to z)
# [0-9] the item match one of this number (0 to 9)
# (abc|def) match the first or the second pattern
# It is possible to combine expression like:
# [A-Z0-9] search for an alphanumeric
# (abc|def)+ at least one of abc or def is matched