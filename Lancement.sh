#!/bin/bash

#L'objectif de ce scirpt est de lancer une charge de travail avec l'ordonnancement EDF disponnible sur linux.
# chrt -d -T <runtime> -D <deadline> -P <period> 0 <command> <command options>
 chrt -d -T <runtime> -D <deadline> -P <period> 0 <command> <command options>
