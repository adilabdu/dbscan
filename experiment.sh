#!/bin/sh
# Experiments for 3 DBSCAN iterations

if [ $1 == 'twitter-1k' ]
then
    DATA_DIR="./dataset/twitter-subsets/twitter-1000.csv"
    SIZE=1000
    DIM=2
    MIN_SAMPLE=40
    EPS=0.01
elif [ $1 == 'twitter-10k' ]
then
    DATA_DIR="./dataset/twitter-subsets/twitter-10000.csv"
    SIZE=10000
    DIM=2
    MIN_SAMPLE=40
    EPS=0.01
elif [ $1 == 'twitter-50k' ]
then
    DATA_DIR="./dataset/twitter-subsets/twitter-50000.csv"
    SIZE=50000
    DIM=2
    MIN_SAMPLE=40
    EPS=0.01
elif [ $1 == 'twitter-100k' ]
then
    DATA_DIR="./dataset/twitter-subsets/twitter-100k.csv"
    SIZE=100000
    DIM=2
    MIN_SAMPLE=40
    EPS=0.01
elif [ $1 == 'twitter-1mil' ]
then
    DATA_DIR="./dataset/twitter-subsets/twitter-1mil.csv"
    SIZE=1000000
    DIM=2
    MIN_SAMPLE=40
    EPS=0.01

elif [ $1 == 'wine' ]
then
    DATA_DIR="./dataset/wine.csv"
    SIZE=178
    DIM=13
    MIN_SAMPLE=26
    EPS=51
elif [ $1 == 'glass' ]
then
    DATA_DIR="./dataset/glass.csv"
    SIZE=214
    DIM=10
    MIN_SAMPLE=20
    EPS=2
elif [ $1 == 'ecoli' ]
then
    DATA_DIR="./dataset/ecoli.csv"
    SIZE=336
    DIM=8
    MIN_SAMPLE=16
    EPS=0.2
elif [ $1 == 'yeast' ]
then
    DATA_DIR="./dataset/yeast.csv"
    SIZE=1484
    DIM=8
    MIN_SAMPLE=16
    EPS=0.09
elif [ $1 == 'rock' ]
then
    DATA_DIR="./dataset/rock.csv"
    SIZE=4121
    DIM=2
    MIN_SAMPLE=4
    EPS=25000
elif [ $1 == 'mfcc' ]
then
    DATA_DIR="./dataset/mfcc.csv"
    SIZE=7195
    DIM=22
    MIN_SAMPLE=44
    EPS=1.4

elif [ $1 == 'hepta' ]
then
    DATA_DIR="./dataset/fcps/hepta.csv"
    SIZE=212
    DIM=3
    MIN_SAMPLE=4
    EPS=0.75
elif [ $1 == 'lsun' ]
then
    DATA_DIR="./dataset/fcps/lsun.csv"
    SIZE=400
    DIM=2
    MIN_SAMPLE=4
    EPS=0.5
elif [ $1 == 'tetra' ]
then
    DATA_DIR="./dataset/fcps/tetra.csv"
    SIZE=400
    DIM=3
    MIN_SAMPLE=4
    EPS=0.4
elif [ $1 == 'target' ]
then
    DATA_DIR="./dataset/fcps/target.csv"
    SIZE=770
    DIM=2
    MIN_SAMPLE=4
    EPS=0.25
elif [ $1 == 'atom' ]
then
    DATA_DIR="./dataset/fcps/atom.csv"
    SIZE=800
    DIM=3
    MIN_SAMPLE=7
    EPS=15
elif [ $1 == 'twodiamonds' ]
then
    DATA_DIR="./dataset/fcps/twodiamonds.csv"
    SIZE=800
    DIM=2
    MIN_SAMPLE=50
    EPS=0.4
elif [ $1 == 'chainlink' ]
then
    DATA_DIR="./dataset/fcps/chainlink.csv"
    SIZE=1000
    DIM=3
    MIN_SAMPLE=4
    EPS=0.15
elif [ $1 == 'wingnut' ]
then
    DATA_DIR="./dataset/fcps/wingnut.csv"
    SIZE=1016
    DIM=2
    MIN_SAMPLE=4
    EPS=0.25
elif [ $1 == 'golfball' ]
then
    DATA_DIR="./dataset/fcps/golfball.csv"
    SIZE=4002
    DIM=3
    MIN_SAMPLE=4
    EPS=0.07
else
    echo "\nERROR: No dataset with given name\n"
    exit
fi

./dbscan-runs.sh original.cpp $DATA_DIR $SIZE $DIM $MIN_SAMPLE $EPS

./dbscan-runs.sh revised.cpp $DATA_DIR $SIZE $DIM $MIN_SAMPLE $EPS

./dbscan-runs.sh proposed.cpp $DATA_DIR $SIZE $DIM $MIN_SAMPLE $EPS
