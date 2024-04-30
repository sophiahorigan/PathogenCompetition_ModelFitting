#1645205092
exit
#1646926148
ls
#1646926624
module load gcc/5.4.0
#1646926633
module load gsl/2.3
#1646926820
scp -r /Users/sophiahorigan/Documents/Github/PathogenCompetition_ModelFitting/META_disp_ls_nostoch/ shorigan@gardner.cri.uchicago.edu:/home/shorigan/
#1646926945
scp -r /Users/sophiahorigan/Desktop/issues/ shorigan@gardner.cri.uchicago.edu:/home/shorigan/
#1646927060
cri-datamover.cri.uchicago.edu
#1646927135
scp -r /Users/sophiahorigan/Desktop/issues/ cri-datamover.cri.uchicago.edu
scp -r /Users/sophiahorigan/Documents/Github/PathogenCompetition_ModelFitting/META_disp_ls_nostoch/ shorigan@cri-datamover.cri.uchicago.edu:/home/shorigan/
#1646927659
ls
#1646927720
cd META_disp_ls_nostoch/
#1646927724
ls
#1646927745
./compiler.sh metapopulation_fvco_disp
#1646928903
ls
#1646928906
cd ..
#1646928907
rm -r META_disp_ls_nostoch/
#1646928928
cd META_disp_ls_nostoch/
#1646928929
./compiler.sh metapopulation_fvco_disp
#1646928974
msub -t 1-100 ./metapopulation_fvco_disp
#1646928990
ls
#1646928997
qsub gard_run.pbs 
#1646929000
ls
#1646929013
showq
#1646929021
qstat
#1646929061
msub -t 1-100 gard_run.pbs 
#1646929074
qstat
#1646929384
ls
#1646929403
nano Moab.o32995988
#1646929626
qstat
#1646929629
ls
#1646929647
nano Moab.o32995997
#1646929667
qsub gard_run.pbs
#1646929675
qstat
#1646930211
ls
#1646930301
pwd
#1646930323
cd ..
#1646930325
rm -r META_disp_ls_nostoch/
#1646930345
cd META_disp_ls_nostoch/
#1646930351
./compiler.sh metapopulation_fvco_disp
#1646930357
qsub gard_run.pbs
#1646930362
qstat
#1646931325
ls
#1646931395
cd ,,
#1646931396
cd ..
#1646931398
rm -r META_disp_ls_nostoch/
#1646931408
cd META_disp_ls_nostoch/
#1646931411
./compiler.sh metapopulation_fvco_disp
#1646931416
qsub gard_run.pbs
#1646931421
qstat
#1697573602
ls
#1697573606
rm -r META_disp_ls_nostoch/
#1697573609
cd MODEL
#1697573610
ls
#1697573617
./compiler.sh metapopulation_fvco_disp
#1697573710
sudo chmod +x
#1697582906
1
#1697582911
ls
#1697652342
pwd
#1697652350
ls -la
#1697652361
cd MODEL/
#1697652365
ls -la
#1697652402
vim PCAsd_21.txt 
#1697653839
exit
#1697656437
ls -la
#1697656445
cd MODEL/
#1697656447
ls -la
#1697656463
./compiler.sh 
#1697656498
vim compiler.sh 
#1697656649
ls -la
#1697656694
vim compiler.sh 
#1697656845
./compiler.sh 
#1697656857
vim compiler.sh 
#1697658280
cd MODEL
#1697658282
./compiler.sh 
#1697658294
./compiler.sh metapopulation_fvco_disp
#1697658298
ls
#1697658315
./compiler.sh metapopulation_fvco_disp
#1697658326
module load gcc
#1697658328
./compiler.sh metapopulation_fvco_disp
#1697658383
./compiler.sh linesearch_mcmc
#1697658391
module load gsl
#1697658393
./compiler.sh linesearch_mcmc
#1697658687
cd
#1697658690
exit
#1697658902
./linesearch_mcmc 21 3
#1697652270
cd /home/shorigan/
#1697652281
ll
#1697652284
cd MODEL/
#1697652286
ll
#1697652311
vi PCAsd_21.txt 
#1698235988
ls
#1698235991
rm -r MODEL
#1698236083
ls
#1698236086
cd MODEL
#1698236090
./compiler.sh linesearch_mcmc
#1698352496
ls
#1698352511
rm -r MODEL
#1698352573
ls
#1698352577
cd MODEL
#1698352579
./compiler.sh linesearch_mcmc
#1698352588
module load gsl
#1698923631
ls
#1698923633
rm -r MODEL
#1698923753
ls
#1698923796
cd MODEL
#1698923797
ls
#1698923806
module load gcc
#1698923809
module load gsl
#1698923813
./compiler.sh linesearch_mcmc
#1698937465
ls
#1698937467
cd MODEL
#1698937472
chmod 0700 compiler.sh 
#1698937475
./compiler.sh linesearch_mcmc
#1698937486
module load gsl
#1698937506
module spider gsl
#1698957416
cd MODEL
#1698957418
./compiler.sh linesearch_mcmc
#1698957429
module load gsl
#1698957438
module spider gsl
#1698957455
o
#1698957484
      gcc/11.3.0
#1698957484
      gcc/12.1.0
#1698957484
      intel/2022.2
#1698957488
      llvm/14.0.5
#1698957495
module load gcc/11.3.0
#1698957504
module load gcc/12.1.0
#1698957518
module load gsl
#1698957531
cd MODEL
#1698957535
./compiler.sh linesearch_mcmc
#1698957546
sbatch arrayjob.sbatch 
#1698957626
ls
#1698957633
nano arrayjob.sbatch 
#1698957655
sbatch arrayjob.sbatch 
#1698957663
squeue --user=shorigan
#1699197789
ls
#1699197795
squeue --user=shorigan
#1699198361
rm -r MODEL
#1699198486
ls
#1699198512
cd MODEL
#1699198516
./compiler.sh linesearch_mcmc
#1699198522
chmod 0700 compiler.sh
#1699198524
./compiler.sh linesearch_mcmc
#1699198528
module load gsl
#1699198533
module load gcc
#1699198537
module load gsl
#1699198541
./compiler.sh linesearch_mcmc
#1699198549
sbatch arrayjob.sbatch 
#1699198559
nano arrayjob.sbatch 
#1699198587
sbatch arrayjob.sbatch 
#1699306075
squeue --user=shorigan
#1699306080
scancel --user=shorigan
#1699307409
squeue --user=shorigan
#1699307557
rm -r MODEL
#1699307587
ls
#1699307589
cd MODEL
#1699307596
chmod 0700 arrayjob.sbatch 
#1699307599
module load gcc
#1699307602
module load gsl
#1699307608
./compiler.sh linesearch_mcmc
#1699307615
chmod 0700 compiler.sh
#1699307617
./compiler.sh linesearch_mcmc
#1699307626
sbatch arrayjob.sbatch 
#1699307643
squeue --user=shorigan
#1699311397
scancel --user=shorigan
#1699311904
rm -r MODEL
#1699312007
ls
#1699312009
cd MODEL
#1699312013
chmod 0700 compiler.sh
#1699312018
module load gcc
#1699312027
module load gsl
#1699312032
./compiler.sh linesearch_mcmc
#1699312045
./linesearch_mcmc 45 3
#1699312067
sbatch arrayjob.sbatch 
#1699365681
squeue --user=shorigan
#1699365683
ls
#1699366108
rm -r MODEL
#1699366169
cd MODEL
#1699366173
chmod 0700 batch_job.sh 
#1699366178
chmod 0700 arrayjob.sbatch 
#1699366183
module load gcc
#1699366185
module load gsl
#1699366190
./compiler.sh linesearch_mcmc
#1699366196
chmod 0700 compiler.sh
#1699366204
./compiler.sh linesearch_mcmc
#1699366218
./linesearch_mcmc 45 3
#1699366229
nano arrayjob.sbatch 
#1699366243
sbatch arrayjob.sbatch 
#1699366285
squeue --user=shorigan
#1699382828
scancel --user=shorigan
#1699383410
rm -r MODEL
#1699383446
cd MODEL
#1699383451
chmod 0700 compiler.sh
#1699383456
module load gcc
#1699383458
module load gsl
#1699383465
./compiler.sh linesearch_mcmc
#1699383473
./linesearch_mcmc 45 3
#1699383492
cd ..
#1699383494
rm -r MODEL
#1699383576
cd MODEL
#1699383584
chmod 0700 compiler.sh
#1699383588
module load gcc
#1699383590
module load gsl
#1699383595
cmhod 0700 batch_job.sh 
#1699383601
chmod 0700 arrayjob.sbatch 
#1699383608
./compiler.sh linesearch_mcmc
#1699383614
cd ..
#1699383615
rm -r MODEL
#1699383648
cd MODEL
#1699383651
cmhod 0700 batch_job.sh 
#1699383655
chmod 0700 arrayjob.sbatch 
#1699383660
chmod 0700 compiler.sh
#1699383664
module load gcc
#1699383667
module load gsl
#1699383670
./compiler.sh linesearch_mcmc
#1699383681
sbatch arrayjob.sbatch 
#1699383697
squeue --user=shorigan
#1699464912
scancel --user=shorigan
#1699466348
rm -r MODEL
#1699466401
ls
#1699466404
cd MODEL
#1699466413
chmod 0700 compiler.sh
#1699466417
./compiler.sh linesearch_mcmc
#1699466422
module load gcc
#1699466429
module load gsl
#1699466431
./compiler.sh linesearch_mcmc
#1699466441
./linesearch_mcmc 45 2
#1699467376
cd ..
#1699467377
rm -r MODEL
#1699467417
cd MODEL
#1699467422
chmod 0700 compiler.sh
#1699467425
module load gcc
#1699467428
module load gsl
#1699467430
./compiler.sh linesearch_mcmc
#1699467455
cd ..
#1699467456
rm -r MODEL
#1699467470
cd MODEL
#1699467472
module load gcc
#1699467474
module load gsl
#1699467477
chmod 0700 compiler.sh
#1699467479
./compiler.sh linesearch_mcmc
#1699467486
./linesearch_mcmc 45 2
#1699467624
cd ..
#1699467627
rm -r MODEL
#1699467643
cd MODEL
#1699467651
chmod 0700 compiler.sh
#1699467654
module load gcc
#1699467657
module load gsl
#1699467661
./compiler.sh linesearch_mcmc
#1699467666
./linesearch_mcmc 45 2
#1699467881
cd ..
#1699467882
rm -r MODEL
#1699467900
cd MODEL
#1699467907
module load gcc
#1699467909
module load gsl
#1699467913
chmod 0700 compiler.sh
#1699467916
./compiler.sh linesearch_mcmc
#1699467921
./linesearch_mcmc 45 2
#1699468008
cd ..
#1699468009
rm -r MODEL
#1699468030
cd MODEL
#1699468034
module load gcc
#1699468036
module load gsl
#1699468039
chmod 0700 compiler.sh
#1699468041
./compiler.sh linesearch_mcmc
#1699468045
./linesearch_mcmc 45 2
#1699468060
cd ..
#1699468061
rm -r MODEL
#1699468079
cd MODEL
#1699468081
module load gcc
#1699468083
module load gsl
#1699468085
chmod 0700 compiler.sh
#1699468087
./compiler.sh linesearch_mcmc
#1699468090
./linesearch_mcmc 45 2
#1699531103
ls
#1699531110
rm -r MODEL
#1699531411
cd MODEL
#1699531416
module load gcc
#1699531419
module load gsl
#1699531422
chmod 0700 compiler.sh
#1699531426
./compiler.sh linesearch_mcmc
#1699531435
./linesearch_mcmc 1 1
#1699531462
sbatch arrayjob.sbatch 
#1699532042
scancel --user=shorigan
#1699532046
cd ..
#1699532047
rm -r MODEL
#1699532078
cd MODEL
#1699532081
module load gcc
#1699532084
module load gsl
#1699532088
chmod 0700 compiler.sh
#1699532091
./compiler.sh linesearch_mcmc
#1699532099
sbatch arrayjob.sbatch 
#1699533431
cd ..
#1699533433
rm -r MODEL
#1699533453
cd MODEL
#1699533456
module load gcc
#1699533459
module load gsl
#1699533461
chmod 0700 compiler.sh
#1699533464
./compiler.sh linesearch_mcmc
#1699533476
sbatch arrayjob.sbatch 
#1699566928
1
#1699566934
squeue --user=shorigan
#1699632084
scancel --user=shorigan
#1699632762
rm -r MODEL
#1699632851
cd MODEL
#1699632856
module load gcc
#1699632859
module load gsl
#1699632864
chmod 0700 compiler.sh
#1699632871
./compiler.sh linesearch_mcmc
#1699632907
sbatch arrayjob.sbatch 
#1699885246
rm -r MODEL
#1699885275
cd MODEL
#1699885278
module load gcc
#1699885281
module load gsl
#1699885284
chmod 0700 compiler.sh
#1699885286
./compiler.sh linesearch_mcmc
#1699885294
sbatch arrayjob.sbatch 
#1699984161
squeue --user=shorigna
#1699984172
squeue --user=shorigan
#1699986049
rm -r MODEL
#1699986072
cd MODEL
#1699986075
module load gcc
#1699986078
module load gsl
#1699986081
chmod 0700 compiler.sh
#1699986083
./compiler.sh linesearch_mcmc
#1699986105
cd ,,
#1699986106
cd ..
#1699986108
rm -r MODEL
#1699986147
cd MODEL
#1699986150
module load gcc
#1699986152
module load gsl
#1699986153
chmod 0700 compiler.sh
#1699986155
./compiler.sh linesearch_mcmc
#1699986227
./linesearch_mcmc 1 3
#1699986325
cd .
#1699986329
cd ..
#1699986330
rm -r MODEL
#1699986346
cd MODEL
#1699986349
module load gcc
#1699986351
module load gsl
#1699986353
chmod 0700 compiler.sh
#1699986356
./compiler.sh linesearch_mcmc
#1699986360
./linesearch_mcmc 1 3
#1699986632
cd ..
#1699986634
rm -r MODEL
#1699986646
cd MODEL
#1699986649
module load gcc
#1699986651
module load gsl
#1699986653
chmod 0700 compiler.sh
#1699986655
./compiler.sh linesearch_mcmc
#1699986659
./linesearch_mcmc 1 3
#1699986790
cd ..
#1699986791
rm -r MODEL
#1699986818
cd MODEL
#1699986820
module load gcc
#1699986827
module load gsl
#1699986829
chmod 0700 compiler.sh
#1699986833
./compiler.sh linesearch_mcmc
#1699986837
./linesearch_mcmc 1 3
#1699987131
cd ..
#1699987132
rm -r MODEL
#1699987151
cd MODEL
#1699987153
module load gcc
#1699987156
module load gsl
#1699987158
chmod 0700 compiler.sh
#1699987160
./compiler.sh linesearch_mcmc
#1699987223
cd ..
#1699987224
rm -r MODEL
#1699987238
cd MODEL
#1699987241
module load gcc
#1699987244
module load gsl
#1699987246
chmod 0700 compiler.sh
#1699987248
./compiler.sh linesearch_mcmc
#1699987258
./linesearch_mcmc 1 3
#1699987585
cd ..
#1699987588
rm -r MODEL
#1699987605
cd MODEL
#1699987607
module load gcc
#1699987609
module load gsl
#1699987612
chmod 0700 compiler.sh
#1699987614
./compiler.sh linesearch_mcmc
#1699987628
cd ..
#1699987629
rm -r MODEL
#1699987642
cd MODEL
#1699987644
module load gcc
#1699987651
module load gsl
#1699987654
chmod 0700 compiler.sh
#1699987657
./compiler.sh linesearch_mcmc
#1699987671
./linesearch_mcmc 1 3
#1699987727
chmod 0700 batch_job.sh 
#1699987735
chmod 0700 arrayjob.sbatch 
#1699987743
sbatch arrayjob.sbatch 
#1700153184
squeue --user=shorigan
#1700156241
rm -r MODEL
#1700156280
cd MODEL
#1700156283
module load gcc
#1700156287
module load gsl
#1700156292
chmod 0700 compiler.sh
#1700156295
./compiler.sh linesearch_mcmc
#1700156302
./linesearch_mcmc 1 3
#1700156588
cd ..
#1700156590
rm -r MODEL
#1700156605
cd MODEL
#1700156607
module load gcc
#1700156610
squeue --user=shorigan
#1700156615
module load gsl
#1700156618
chmod 0700 compiler.sh
#1700156622
./compiler.sh linesearch_mcmc
#1700156629
./linesearch_mcmc 1 3
#1700156694
cd .
#1700156696
cd ..
#1700156697
rm -r MODEL
#1700156729
cd MODEL
#1700156734
module load gcc
#1700156738
squeue --user=shorigan
#1700156741
module load gsl
#1700156744
./compiler.sh linesearch_mcmc
#1700156750
chmod 0700 compiler.sh 
#1700156751
./compiler.sh linesearch_mcmc
#1700156758
./linesearch_mcmc 1 3
#1700156870
cd ..
#1700156874
rm -r MODEL
#1700156891
cd MODEL
#1700156896
module load gcc
#1700156900
module load gsl
#1700156904
chmod 0700 compiler.sh 
#1700156906
./linesearch_mcmc 1 3
#1700156909
./compiler.sh linesearch_mcmc
#1700156918
./linesearch_mcmc 1 3
#1700157459
cd ..
#1700157460
rm -r MODEL
#1700157478
cd MODEL
#1700157484
module load gcc gsl
#1700157491
chmod 0700 compiler.sh
#1700157499
./compiler.sh linesearch_mcmc
#1700157511
./linesearch_mcmc 3 1
#1700157562
cd ..
#1700157563
rm -r MODEL
#1700157576
cd MODEL
#1700157580
module load gcc gsl
#1700157585
chmod 0700 compiler.sh
#1700157589
./compiler.sh linesearch_mcmc
#1700157594
./linesearch_mcmc 3 1
#1700157743
cd ..
#1700157746
rm -r MODEL
#1700157764
cd MODEL
#1700157771
chmod 0700 compiler.sh
#1700157774
./linesearch_mcmc 3 1
#1700157776
./compiler.sh linesearch_mcmc
#1700157782
./linesearch_mcmc 3 1
#1700157919
d ..
#1700157921
cd ..
#1700157922
rm -r MODEL
#1700157936
cd MODEL
#1700157940
chmod 0700 compiler.sh
#1700157943
./compiler.sh linesearch_mcmc
#1700157950
./linesearch_mcmc 3 1
#1700158095
cd ..
#1700158097
rm -r MODEL
#1700158113
cd MODEL
#1700158115
chmod 0700 compiler.sh
#1700158117
./compiler.sh linesearch_mcmc
#1700158124
./linesearch_mcmc 3 1
#1700158294
cd ..
#1700158296
rm -r MODEL
#1700158318
cd MODEL
#1700158321
./compiler.sh linesearch_mcmc
#1700158324
chmod 0700 compiler.sh
#1700158326
./compiler.sh linesearch_mcmc
#1700158333
./linesearch_mcmc 3 1
#1700158675
cd ..
#1700158676
rm -r MODEL
#1700158690
cd MODEL
#1700158692
chmod 0700 compiler.sh
#1700158695
./compiler.sh linesearch_mcmc
#1700158701
./linesearch_mcmc 3 1
#1700159024
cd ..
#1700159027
rm -r MODEL
#1700159038
cd MODEL
#1700159040
chmod 0700 compiler.sh
#1700159043
./compiler.sh linesearch_mcmc
#1700159049
./linesearch_mcmc 3 1
#1700159460
d ..
#1700159462
cd ..
#1700159465
rm -r MODEL
#1700159479
cd MODEL
#1700159484
chmod 0700 compiler.sh
#1700159487
./compiler.sh linesearch_mcmc
#1700159497
./linesearch_mcmc 3 1
#1700159563
cd ..
#1700159566
rm -r MODEL
#1700159578
cd MODEL
#1700159580
chmod 0700 compiler.sh
#1700159581
./compiler.sh linesearch_mcmc
#1700159586
./linesearch_mcmc 3 1
#1700160264
cd //
#1700160266
cd ..
#1700160269
ls
#1700160274
cd home
#1700160275
ls
#1700160277
cd shorigan
#1700160279
ls
#1700160281
rm -r MODEL
#1700160304
cd MODEL
#1700160312
chmod 0700 compiler.sh
#1700160316
./compiler.sh linesearch_mcmc
#1700160325
./linesearch_mcmc 3 1
#1700160443
d ..
#1700160445
cd ..
#1700160447
rm -r MODEL
#1700160489
cd MODEL
#1700160495
chmod 0700 compiler.sh
#1700160497
./compiler.sh linesearch_mcmc
#1700160503
./linesearch_mcmc 3 1
#1700160741
cd ..
#1700160743
rm -r MODEL
#1700160756
cd MODEL
#1700160762
chmod 0700 compiler.sh
#1700160764
./compiler.sh linesearch_mcmc
#1700160769
./linesearch_mcmc 3 1
#1700161062
cd ..
#1700161063
rm -r MODEL
#1700161081
cd MODEL
#1700161083
chmod 0700 compiler.sh
#1700161086
./compiler.sh linesearch_mcmc
#1700161091
./linesearch_mcmc 3 1
#1700161419
cd ..
#1700161421
rm -r MODEL
#1700161487
cd MODEL
#1700161494
chmod 0700 compiler.sh
#1700161496
./compiler.sh linesearch_mcmc
#1700161501
./linesearch_mcmc 3 1
#1700161589
cd ..
#1700161592
rm -r MODEL
#1700161631
cd MODEL
#1700161635
chmod 0700 compiler.sh
#1700161637
./compiler.sh linesearch_mcmc
#1700161641
./linesearch_mcmc 3 1
#1700162810
cd ..
#1700162815
rm -r MODEL
#1700162828
cd MODEL
#1700162831
chmod 0700 compiler.sh
#1700162834
./compiler.sh linesearch_mcmc
#1700162838
./linesearch_mcmc 3 1
#1700162967
cd ..
#1700162968
rm -r MODEL
#1700162985
cd MODEL
#1700163004
chmod 0700 compiler.sh
#1700163006
./compiler.sh linesearch_mcmc
#1700163012
./linesearch_mcmc 3 1
#1700163301
cd ..
#1700163303
rm -r MODEL
#1700163330
cd MODEL
#1700163333
chmod 0700 compiler.sh
#1700163335
./compiler.sh linesearch_mcmc
#1700163339
./linesearch_mcmc 3 1
#1700163459
cd ..
#1700163461
rm -r MODEL
#1700163475
cd MODEL
#1700163478
chmod 0700 compiler.sh
#1700163480
./compiler.sh linesearch_mcmc
#1700163485
./linesearch_mcmc 3 1
#1700163577
cd ..
#1700163579
rm -r MODEL
#1700163588
cd MODEL
#1700163593
chmod 0700 compiler.sh
#1700163596
./compiler.sh linesearch_mcmc
#1700163600
./linesearch_mcmc 3 1
#1700163752
cd ..
#1700163756
rm -r MODEL
#1700163769
cd MODEL
#1700163772
chmod 0700 compiler.sh
#1700163774
./compiler.sh linesearch_mcmc
#1700163778
./linesearch_mcmc 3 1
#1700163820
cd ..
#1700163822
rm -r MODEL
#1700163843
cd MODEL
#1700163846
chmod 0700 compiler.sh
#1700163847
./compiler.sh linesearch_mcmc
#1700163851
./linesearch_mcmc 3 1
#1700164020
cd ..
#1700164022
rm -r MODEL
#1700164045
cd MODEL
#1700164048
chmod 0700 compiler.sh
#1700164050
./compiler.sh linesearch_mcmc
#1700164055
./linesearch_mcmc 3 1
#1700164186
cd ..
#1700164188
rm -r MODEL
#1700164201
cd MODEL
#1700164203
chmod 0700 compiler.sh
#1700164205
./compiler.sh linesearch_mcmc
#1700164209
./linesearch_mcmc 3 1
#1700164302
cd ..
#1700164304
rm -r MODEL
#1700164312
cd MDOEL
#1700164315
cd MODEL
#1700164317
chmod 0700 compiler.sh
#1700164319
./compiler.sh linesearch_mcmcc
#1700164323
./compiler.sh linesearch_mcmc
#1700164328
./linesearch_mcmc 3 1
#1700164390
cd ..
#1700164391
rm -r MODEL
#1700164404
cd MODEL
#1700164408
chmod 0700 compiler.sh
#1700164410
./compiler.sh linesearch_mcmc
#1700164414
./linesearch_mcmc 3 1
#1700164535
cd ..
#1700164536
rm -r MODEL
#1700164550
cd MODEL
#1700164553
chmod 0700 compiler.sh
#1700164555
./compiler.sh linesearch_mcmc
#1700164559
./linesearch_mcmc 3 1
#1700164718
cd ..
#1700164721
rm -r MODEL
#1700164736
cd MODEL
#1700164740
chmod 0700 compiler.sh
#1700164746
./compiler.sh linesearch_mcmc
#1700164754
./linesearch_mcmc 3 1
#1700165759
cd ..
#1700165760
rm -r MODEL
#1700165833
cd MODEL
#1700165835
chmod 0700 compiler.sh
#1700165837
./compiler.sh linesearch_mcmc
#1700165842
./linesearch_mcmc 3 1
#1700166298
d ..
#1700166300
cd ..
#1700166302
rm -r MODEL
#1700166327
cd MODEL
#1700166330
chmod 0700 compiler.sh
#1700166332
./compiler.sh linesearch_mcmc
#1700166340
./linesearch_mcmc 3 1
#1700167039
cd ..
#1700167044
rm -r MODEL
#1700167058
cd MODEL
#1700167062
chmod 0700 compiler.sh
#1700167065
./compiler.sh linesearch_mcmc
#1700167071
./linesearch_mcmc 3 1
#1700167185
cd ..
#1700167188
rm -r MODEL
#1700167223
cd MODEL
#1700167226
chmod 0700 compiler.sh
#1700167229
./compiler.sh linesearch_mcmc
#1700167235
./linesearch_mcmc 3 1
#1700167381
cd ..
#1700167384
rm -r MODEL
#1700167421
cd MODEL
#1700167428
chmod 0700 compiler.sh
#1700167435
./compiler.sh linesearch_mcmc
#1700167442
./linesearch_mcmc 3 1
#1700167723
cd ..
#1700167724
rm -r MODEL
#1700167926
cd MODEL
#1700167929
chmod 0700 compiler.sh
#1700167930
./compiler.sh linesearch_mcmc
#1700167934
./linesearch_mcmc 3 1
#1700167965
cd ..
#1700167967
rm -r MODEL
#1700167980
cd MODEL
#1700167985
chmod 0700 compiler.sh
#1700167987
./compiler.sh linesearch_mcmc
#1700167991
./linesearch_mcmc 3 1
#1700168032
./linesearch_mcmc 1 1
#1700168258
cd ..
#1700168259
rm -r MODEL
#1700168267
cd MODEL
#1700168277
chmod 0700 compiler.sh
#1700168279
./linesearch_mcmc 3 1
#1700168282
./compiler.sh linesearch_mcmc
#1700168287
./linesearch_mcmc 3 1
#1700168316
./linesearch_mcmc 1 1
#1700168846
cd ..
#1700168848
rm -r MODEL
#1700168857
cd MODEL
#1700168861
./compiler.sh linesearch_mcmc
#1700168866
chmod 0700 compiler.sh
#1700168869
./compiler.sh linesearch_mcmc
#1700168874
./linesearch_mcmc 1 1
#1700169375
cd ..
#1700169376
rm -r MODEL
#1700169391
cd MODEL
#1700169394
chmod 0700 compiler.sh
#1700169396
./compiler.sh linesearch_mcmc
#1700169401
./linesearch_mcmc 1 1
#1700169428
cd ..
#1700169430
rm -r MODEL
#1700169508
cd MODEL
#1700169523
chmod 0700 compiler.sh
#1700169526
./compiler.sh linesearch_mcmc
#1700169531
./linesearch_mcmc 1 1
#1700169563
cd ,,
#1700169565
cd ..
#1700169568
rm -r MODEL
#1700169579
cd MODEL
#1700169582
chmod 0700 compiler.sh
#1700169585
./compiler.sh linesearch_mcmc
#1700169589
./linesearch_mcmc 1 1
#1700169641
cd ..
#1700169642
rm -r MODEL
#1700169657
cd MODEL
#1700169663
chmod 0700 compiler.sh
#1700169666
./compiler.sh linesearch_mcmc
#1700169670
./linesearch_mcmc 1 1
#1700169692
./linesearch_mcmc 21 1
#1700169758
./linesearch_mcmc 1 1
#1700169777
./linesearch_mcmc 21 1
#1700169832
./linesearch_mcmc 45 1
#1700169925
cd ..
#1700169927
rm -r MODEL
#1700169935
cd MODEL
#1700169940
chmod 0700 compiler.sh
#1700169944
./compiler.sh linesearch_mcmc
#1700169965
./linesearch_mcmc 1 1
#1700169982
./linesearch_mcmc 45 1
#1700169994
./linesearch_mcmc 21 1
#1700170328
cd ..
#1700170329
rm -r MODEL
#1700170376
chmod 0700 compiler.sh
#1700170384
cd MODEL
#1700170388
chmod 0700 compiler.sh
#1700170390
./compiler.sh linesearch_mcmc
#1700170401
./linesearch_mcmc 1 3
#1700170871
cd ..
#1700170872
rm -r MODEL
#1700170885
cd MODEL
#1700170890
chmod 0700 compiler.sh
#1700170895
./compiler.sh linesearch_mcmc
#1700170901
./linesearch_mcmc 1 3
#1700171020
cd ..
#1700171022
rm -r MODEL
#1700171048
cd MODEL
#1700171050
./compiler.sh linesearch_mcmc
#1700171052
chmod 0700 compiler.sh
#1700171055
./compiler.sh linesearch_mcmc
#1700171060
./linesearch_mcmc 1 3
#1700171096
cd ..
#1700171098
rm -r MODEL
#1700171105
cd MODEL
#1700171120
chmod 0700 compiler.sh
#1700171123
./compiler.sh linesearch_mcmc
#1700171127
./linesearch_mcmc 1 3
#1700171238
cd ..
#1700171240
rm -r MODEL
#1700171298
cd MODEL
#1700171301
chmod 0700 compiler.sh
#1700171303
./compiler.sh linesearch_mcmc
#1700171308
./linesearch_mcmc 1 3
#1700171320
chmod 0700 arrayjob.sbatch 
#1700171324
sbatch arrayjob.sbatch 
#1700234241
squeue --user=shorigan
#1700234243
ls
#1700234245
rm -r MODEL
#1700234304
cd MODEL
#1700234314
module load gcc gsl
#1700234317
chmod 0700 arrayjob.sbatch 
#1700234320
chmod 0700 compiler.sh
#1700234324
./compiler.sh linesearch_mcmc
#1700234336
sbatch arrayjob.sbatch 
#1700500697
rm -r MODEL
#1700500736
cd MODEL
#1700500739
module load gcc gsl
#1700500742
chmod 0700 compiler.sh
#1700500744
./compiler.sh linesearch_mcmc
#1700500765
./linesearch_mcmc 1 2
#1700517722
rm -r MODEL
#1700517796
cd MODEL
#1700517955
module load gcc gsl
#1700517958
chmod 0700 compiler.sh
#1700517960
./compiler.sh linesearch_mcmc
#1700517974
sbatch arrayjob.sbatch 
#1701092493
squeue --user=shorigan
#1701092635
ls
#1701092646
squeue --user=shorigan
#1701092701
ls
#1701092803
nano myjob.out
#1701098712
squeue --user=shorigan
#1701098773
ls
#1701098775
cd MODEL_kc2/
#1701098776
ls
#1701098781
module load gcc gsl
#1701098786
chmod 0700 compiler.sh
#1701098790
./compiler.sh linesearch_mcmc
#1701098798
sbatch arrayjob.sbatch 
#1701181939
squeue --user=shorigan
#1701182533
ls
#1701182537
cd MODEL_kc2/
#1701182540
sbatch arrayjob.sbatch 
#1701182546
squeue --user=shorigan
#1701182550
ls
#1701182557
nano slurm-3301198_1.out
#1701182569
nano  'error_$A-4.txt'
#1701182800
module spider openmpi
#1701182892
ls
#1701182896
rm -r MODEL_kc2/
#1701182934
cd MODEL_kc2/
#1701182943
module load gcc gsl
#1701182948
./compiler.sh linesearch_mcmc
#1701182956
chmod 0700 ./compiler.sh linesearch_mcmc
#1701182963
chmod 0700 ./compiler.sh 
#1701182968
./compiler.sh linesearch_mcmc
#1701182985
ls
#1701183002
chmod 0700 arrayjob.sbatch 
#1701183006
sbatch arrayjob.sbatch 
#1701183009
ls
#1701183015
nano 'error_$A-1.txt'
#1701183044
squeue --user=shorigan
#1701183051
nano 'error_$A-1.txt'
#1701183084
cd ..
#1701183086
rm -r MODEL_kc2/
#1701183108
cd MODEL_kc2/
#1701183116
module load gcc gsl
#1701183121
chmod 0700 arrayjob.sbatch 
#1701183125
chmod 0700 ./compiler.sh 
#1701183131
./compiler.sh linesearch_mcmc
#1701183139
sbatch arrayjob.sbatch 
#1701183141
ls
#1701183147
nano 'error_$A-1.txt' 
#1701183168
nano slurm-3313767_1.out
#1701183591
cd ..
#1701183594
rm -r MODEL_kc2/
#1701183653
cd MODEL_kc2/
#1701183657
module load gcc gsl
#1701183661
chmod 0700 ./compiler.sh 
#1701183664
./compiler.sh linesearch_mcmc
#1701183669
sbatch arrayjob.sbatch 
#1701183671
ls
#1701183677
nano 'error_$A-4.txt'
#1701183681
squeue --user=shorigan
#1701201673
scancel --user=shorigan
#1701201680
squeue --user=shorigan
#1701202515
ls
#1701202524
rm -r MODEL
#1701202527
rm -r MODEL_kc2/
#1701203261
cd MODEL
#1701203269
sinteractive
#1701203294
ls
#1701203296
cd MODEL
#1701203302
module load gcc gsl
#1701203306
chmod 0700 ./compiler.sh 
#1701203311
./compiler.sh linesearch_mcmc
#1701203746
cd ..
#1701203748
rm -r MODEL
#1701203761
cd MODEL
#1701203763
module load gcc gsl
#1701203766
chmod 0700 ./compiler.sh 
#1701203768
./compiler.sh linesearch_mcmc
#1701203986
cd ..
#1701203987
rm -r MODEL
#1701204184
cd MODEL
#1701204187
module load gcc gsl
#1701204188
chmod 0700 ./compiler.sh 
#1701204190
./compiler.sh linesearch_mcmc
#1701204756
cd ..
#1701204759
rm -r MODEL
#1701204772
cd MODEL
#1701204775
module load gcc gsl
#1701204777
chmod 0700 ./compiler.sh 
#1701204778
./compiler.sh linesearch_mcmc
#1701204812
./linesearch_mcmc 1 3
#1701204857
d ..
#1701204858
cd ..
#1701204859
rm -r MODEL
#1701204869
cd MODEL
#1701204873
module load gcc gsl
#1701204878
chmod 0700 ./compiler.sh 
#1701204880
./compiler.sh linesearch_mcmc
#1701204885
./linesearch_mcmc 1 3
#1701205127
cd ..
#1701205128
rm -r MODEL
#1701205152
cd MODEL
#1701205156
module load gcc gsl
#1701205158
chmod 0700 ./compiler.sh 
#1701205160
./compiler.sh linesearch_mcmc
#1701205165
./linesearch_mcmc 1 3
#1701205172
sbatch arrayjob.sbatch 
#1701205294
scancel --user=shorigan
#1701205412
sbatch arrayjob.sbatch 
#1701217855
ls
#1701217862
scancel --user=shorigan
#1701217864
rm -r MODEL
#1701218011
cd MODEL
#1701218014
./linesearch_mcmc 1 3
#1701218018
module load gcc gsl
#1701218022
chmod 0700 ./compiler.sh 
#1701218027
./compiler.sh linesearch_mcmc
#1701218034
sbatch arrayjob.sbatch 
#1701259951
squeue --user=shorigan
#1701260681
scancel --user=shorigan
#1701260852
rm -r MODEL
#1701260873
cd MODEL
#1701260876
module load gcc gsl
#1701260879
chmod 0700 ./compiler.sh 
#1701260887
./compiler.sh linesearch_mcmc
#1701260895
./linesearch_mcmc 1 3
#1701261715
cd ..
#1701261717
rm -r MODEL
#1701261758
cd MODEL
#1701261760
chmod 0700 ./compiler.sh 
#1701261764
module load gcc gsl
#1701261767
./compiler.sh linesearch_mcmc
#1701261771
./linesearch_mcmc 1 3
#1701263428
cd ..
#1701263429
rm -r MODEL
#1701263452
cd MODEL
#1701263455
module load gcc gsl
#1701263460
chmod 0700 ./compiler.sh 
#1701263463
./compiler.sh linesearch_mcmc
#1701263467
./linesearch_mcmc 1 3
#1701264867
cd ..
#1701264869
rm -r MODEL
#1701264891
cd MODEL
#1701264894
module load gcc gsl
#1701264897
chmod 0700 ./compiler.sh 
#1701264899
./compiler.sh linesearch_mcmc
#1701264903
./linesearch_mcmc 1 3
#1701264910
rm -r MODEL
#1701264912
cd ..
#1701264914
rm -r MODEL
#1701264922
cd MODEL
#1701264924
chmod 0700 ./compiler.sh 
#1701264928
module load gcc gsl
#1701264931
./compiler.sh linesearch_mcmc
#1701264940
sbatch arrayjob.sbatch 
#1701276124
ls
#1701276127
cd MODEL_2/
#1701276128
ls
#1701276135
module load gcc gsl
#1701276138
chmod 0700 ./compiler.sh 
#1701276141
./compiler.sh linesearch_mcmc
#1701276152
./linesearch_mcmc 1 3
#1701276262
cd .
#1701276263
cd ..
#1701276265
rm -r MODEL
#1701276299
scancel --user=shorigan
#1701276307
rm -r MODEL_2
#1701276324
cd MODEL_2
#1701276328
module load gcc gsl
#1701276332
chmod 0700 ./compiler.sh 
#1701276335
./compiler.sh linesearch_mcmc
#1701276340
./linesearch_mcmc 1 3
#1701276418
cd ..
#1701276420
rm -r MODEL_2
#1701276467
cd MODEL
#1701276470
module load gcc gsl
#1701276472
chmod 0700 ./compiler.sh 
#1701276474
./compiler.sh linesearch_mcmc
#1701276478
./linesearch_mcmc 1 3
#1701276550
cd ..
#1701276551
rm -r MODEL
#1701276575
cd MODEL
#1701276578
module load gcc gsl
#1701276580
chmod 0700 ./compiler.sh 
#1701276584
./compiler.sh linesearch_mcmc
#1701276601
./linesearch_mcmc 1 3
#1701276690
cd ..
#1701276692
rm -r MODEL
#1701276707
cd MODEL
#1701276709
module load gcc gsl
#1701276711
chmod 0700 ./compiler.sh 
#1701276713
./compiler.sh linesearch_mcmc
#1701276717
./linesearch_mcmc 1 3
#1701276853
cd ..
#1701276856
rm -r MODEL
#1701276867
cd MODEL
#1701276869
module load gcc gsl
#1701276872
chmod 0700 ./compiler.sh 
#1701276874
./compiler.sh linesearch_mcmc
#1701276879
./linesearch_mcmc 1 3
#1701278197
cd ..
#1701278198
rm -r MODEL
#1701278230
cd MODEL
#1701278236
module load gcc gsl
#1701278238
chmod 0700 ./compiler.sh 
#1701278241
./compiler.sh linesearch_mcmc
#1701278250
sbatch arrayjob.sbatch 
#1701290376
squeue --user=shorigan
#1701290383
scancel --user=shorigan
#1701296600
squeue --user=shorigan
#1701296601
ls
#1701296605
rm -r MODEL
#1701296621
cd MODEL
#1701296650
module load gcc gsl
#1701296655
chmod 0700 ./compiler.sh 
#1701296659
./compiler.sh linesearch_mcmc
#1701296687
cd ..
#1701296688
rm -r MODEL
#1701296698
cd MODEL
#1701296705
module load gcc gsl
#1701296711
chmod 0700 ./compiler.sh 
#1701296713
./compiler.sh linesearch_mcmc
#1701296720
./linesearch_mcmc 1 3
#1701296732
sbatch arrayjob.sbatch 
#1701355867
squeue --user=shorigan
#1701356908
rm -r MODEL
#1701450442
cd MODEL
#1701450445
module load gcc gsl
#1701450447
chmod 0700 ./compiler.sh 
#1701450450
./compiler.sh linesearch_mcmc
#1701450455
sbatch arrayjob.sbatch 
#1701450621
scancel --user=shorigan
#1701450627
rm -r MODEL
#1701450721
cd MODEL
#1701450724
module load gcc gsl
#1701450727
chmod 0700 ./compiler.sh 
#1701450729
./compiler.sh linesearch_mcmc
#1701450734
sbatch arrayjob.sbatch 
#1701450959
scancel --user=shorigan
#1701450961
rm -r MODEL
#1701450965
cd ..
#1701450966
rm -r MODEL
#1701456700
cd MODEL
#1701456705
module load gcc gsl
#1701456709
chmod 0700 ./compiler.sh 
#1701456712
./compiler.sh linesearch_mcmc
#1701456720
sbatch arrayjob.sbatch 
#1701459487
scancel --user=shorigan
#1701464559
rm -r MODEL
#1701464574
cd MODEL
#1701464578
module load gcc gsl
#1701464599
cd ..
#1701464601
ls
#1701464603
cd MODEL
#1701464603
ls
#1701464610
chmod 0700 ./compiler.sh 
#1701464614
./compiler.sh linesearch_mcmc
#1701464622
cd ..
#1701464628
rm -r MODEL
#1701464699
cd MODEL
#1701464703
chmod 0700 ./compiler.sh 
#1701464705
./compiler.sh linesearch_mcmc
#1701464760
cd ..
#1701464763
rm -r MODEL
#1701464783
cd MODEL
#1701464787
chmod 0700 ./compiler.sh 
#1701464788
./compiler.sh linesearch_mcmc
#1701464795
module load gcc gsl
#1701464801
sbatch arrayjob.sbatch 
#1701648787
squeue --user=shorigan
#1701650359
rm -r MODEL
#1701650558
cd MODEL
#1701650561
module load gcc gsl
#1701650563
chmod 0700 ./compiler.sh 
#1701650566
./compiler.sh linesearch_mcmc
#1701650574
./linesearch_mcmc 1 3
#1701650687
cd ..
#1701650688
rm -r MODEL
#1701650715
cd MODEL
#1701650719
module load gcc gsl
#1701650721
chmod 0700 ./compiler.sh 
#1701650723
./compiler.sh linesearch_mcmc
#1701650727
./linesearch_mcmc 1 3
#1701650752
ls
#1701650795
rm -r accept_1020890_model1 
#1701650797
rm -r mcmc_results_1020890_model1 
#1701650802
sbatch arrayjob.sbatch 
#1701723234
squeue --user=shorigan
#1701790519
scancel --user=shorigan
#1701790775
rm -r MODEL
#1701790801
cd MODEL
#1701790806
module load gcc gsl
#1701790812
chmod 0700 ./compiler.sh 
#1701790816
./compiler.sh linesearch_mcmc
#1701790845
sbatch arrayjob.sbatch 
#1701791924
cd MODEL2
#1701791927
module load gcc gsl
#1701791930
chmod 0700 ./compiler.sh 
#1701791932
./compiler.sh linesearch_mcmc
#1701791937
sbatch arrayjob.sbatch 
#1701791943
squeue --user=shorigan
#1701963893
rm -r MODEL2
#1701963899
squeue --user=shorigan
#1701963937
cd MODEL2
#1701963940
module load gcc gsl
#1701963944
chmod 0700 ./compiler.sh 
#1701963947
./compiler.sh linesearch_mcmc
#1701963954
sbatch arrayjob.sbatch 
#1701963958
squeue --user=shorigan
#1702064349
1
#1702064356
squeue --user=shorigan
#1702064373
scancel --user=shorigan
#1702296593
squeue --user=shorigan
#1702297193
ls
#1702297197
rm -r MODEL
#1702297200
rm -r MODEL2
#1702297276
cd MODEL
#1702297281
chmod 0700 ./compiler.sh 
#1702297286
module load gcc gsl
#1702297290
./compiler.sh linesearch_mcmc
#1702297309
./linesearch_mcmc 1 3
#1702297389
cd ..
#1702297391
rm -r MODEL
#1702297411
cd MODEL
#1702297414
module load gcc gsl
#1702297417
chmod 0700 ./compiler.sh 
#1702297419
./compiler.sh linesearch_mcmc
#1702297424
./linesearch_mcmc 1 3
#1702297492
cd ..
#1702297495
rm -r MODEL
#1702297512
cd MODEL
#1702297515
module load gcc gsl
#1702297517
chmod 0700 ./compiler.sh 
#1702297520
./compiler.sh linesearch_mcmc
#1702297524
./linesearch_mcmc 1 3
#1702297547
sbatch arrayjob.sbatch 
#1702298176
scancel --user=shorigan
#1702298191
cd ..
#1702298193
rm -r MODEL
#1702298212
cd MODEL
#1702298215
chmod 0700 ./compiler.sh 
#1702298218
./compiler.sh linesearch_mcmc
#1702298223
./linesearch_mcmc 1 3
#1702298265
cd ..
#1702298268
cd MODEL
#1702298275
sbatch arrayjob.sbatch 
#1702303268
scancel --user=shorigan
#1702310161
ls
#1702310162
rm -r MODEL
#1702310246
ls
#1702310250
rm -r MODEL
#1702310271
cd MODEL
#1702310279
module load gcc gsl
#1702310282
chmod 0700 ./compiler.sh 
#1702310287
./compiler.sh linesearch_mcmc
#1702310295
sbatch arrayjob.sbatch 
#1702327847
squeue --user=shorigan
#1702328512
ls
#1702328514
rm -r MODEL
#1702328548
cd MODEL
#1702328551
module load gcc gsl
#1702328553
chmod 0700 ./compiler.sh 
#1702328556
./compiler.sh linesearch_mcmc
#1702328564
sbatch arrayjob.sbatch 
#1702328616
ls
#1702328644
squeue --user=shorigan
#1702329015
scancel --user=shorigan
#1702329021
cd ..
#1702329022
rm -r MODEL
#1702329114
cd MODEL
#1702329117
chmod 0700 ./compiler.sh 
#1702329121
./compiler.sh linesearch_mcmc
#1702329127
sbatch arrayjob.sbatch 
#1702329134
squeue --user=shorigan
#1702333530
ls
#1702333532
cd MODEL
#1702333532
ls
#1702333537
mkdir LS
#1702333546
mv LS_* LS
#1702333548
ls
#1702334358
cd ..
#1702334359
rm -r MODEL
#1702334383
cd MODEL
#1702334390
module load gcc gsl
#1702334395
chmod 0700 ./compiler.sh 
#1702334399
./compiler.sh linesearch_mcmc
#1702334406
sbatch arrayjob.sbatch 
#1702334413
squeue --user=shorigan
#1702421647
ls
#1702421650
rm -r MODEL
#1702421683
cd MODEL
#1702421697
module load gcc gsl
#1702421700
chmod 0700 ./compiler.sh 
#1702421702
sbatch arrayjob.sbatch 
#1702421710
squeue --user=shorigan
#1702421711
ls
#1702421727
rm 'error_*
.txt
#1702421744
ls
#1702421781
./compiler.sh linesearch_mcmc
#1702421850
cd ..
#1702421852
rm -r MODEL
#1702421870
cd MODEL
#1702421875
module load gcc gsl
#1702421880
chmod 0700 ./compiler.sh 
#1702421882
./compiler.sh linesearch_mcmc
#1702421888
sbatch arrayjob.sbatch 
#1702421893
squeue --user=shorigan
#1702422311
scancel --user=shorigan
#1702422611
cd ..
#1702422612
rm -r MODEL
#1702422672
cd MODEL
#1702422675
module load gcc gsl
#1702422680
chmod 0700 ./compiler.sh 
#1702422683
./compiler.sh linesearch_mcmc
#1702422971
cd ..
#1702422973
rm -r MODEL
#1702422995
cd MODEL
#1702422997
module load gcc gsl
#1702422999
chmod 0700 ./compiler.sh 
#1702423001
./compiler.sh linesearch_mcmc
#1702423009
sbatch arrayjob.sbatch 
#1702423025
squeue --user=shorigan
#1702423126
scancel --user=shorigan
#1702423134
squeue --user=shorigan
#1702423137
cd ..
#1702423139
rm -r MODEL
#1702423170
cd MODEL
#1702423174
module load gcc gsl
#1702423178
chmod 0700 ./compiler.sh 
#1702423181
./compiler.sh linesearch_mcmc
#1702423187
sbatch arrayjob.sbatch 
#1702423572
scancel --user=shorigan
#1702423609
cd ..
#1702423610
rm -r MODEL
#1702423617
cd MODEL
#1702423634
module load gcc gsl
#1702423637
chmod 0700 ./compiler.sh 
#1702423641
./compiler.sh linesearch_mcmc
#1702423650
sbatch arrayjob.sbatch 
#1702423662
./linesearch_mcmc 1 3
#1702423702
scancel --user=shorigan
#1702423870
cd ..
#1702423872
rm -r MODEL
#1702423895
cd MODEL
#1702423898
chmod 0700 ./compiler.sh 
#1702423902
module load gcc gsl
#1702423905
./compiler.sh linesearch_mcmc
#1702423909
./linesearch_mcmc 1 3
#1702424174
cd ..
#1702424177
rm -r MODEL
#1702424224
cd MODEL
#1702424227
module load gcc gsl
#1702424230
chmod 0700 ./compiler.sh 
#1702424233
./compiler.sh linesearch_mcmc
#1702424240
sbatch arrayjob.sbatch 
#1702477868
squeue --user=shorigan
#1702482161
ls
#1702482163
rm -r MODEL
#1702482238
cd MODEL
#1702482242
module load gcc gsl
#1702482245
chmod 0700 ./compiler.sh 
#1702482249
./compiler.sh linesearch_mcmc
#1702482320
cd ..
#1702482324
rm -r MODEL
#1702482336
cd MODEL
#1702482339
module load gcc gsl
#1702482341
chmod 0700 ./compiler.sh 
#1702482343
./compiler.sh linesearch_mcmc
#1702482359
sbatch arrayjob.sbatch 
#1702482372
cd ..
#1702482378
scancel --user=shorigan
#1702482380
rm -r MODEL
#1702482392
cd MODEL
#1702482394
chmod 0700 ./compiler.sh 
#1702482396
./compiler.sh linesearch_mcmc
#1702482401
module load gcc gsl
#1702482405
sbatch arrayjob.sbatch 
#1702482418
scancel --user=shorigan
#1702482420
cd ..
#1702482421
rm -r MODEL
#1702482471
cd MODEL
#1702482558
squeue --user=shorigan
#1702482577
cd MODEL
#1702482580
module load gcc gsl
#1702482583
chmod 0700 ./compiler.sh 
#1702482588
./compiler.sh linesearch_mcmc
#1702482594
sbatch arrayjob.sbatch 
#1702482598
squeue --user=shorigan
#1702654049
ls
#1702654051
rm -r MODEL
#1702654087
cd MODEL
#1702654090
module load gcc gsl
#1702654093
chmod 0700 ./compiler.sh 
#1702654095
./compiler.sh linesearch_mcmc
#1702654155
cd ..
#1702654156
rm -r MODEL
#1702654174
cd MODEL
#1702654177
module load gcc gsl
#1702654179
chmod 0700 ./compiler.sh 
#1702654181
./compiler.sh linesearch_mcmc
#1702654258
cd ..
#1702654259
rm -r MODEL
#1702654273
cd MODEL
#1702654276
module load gcc gsl
#1702654278
chmod 0700 ./compiler.sh 
#1702654280
./compiler.sh linesearch_mcmc
#1702654289
sbatch arrayjob.sbatch 
#1702654731
scancel --user=shorigan
#1702654733
cd ..
#1702654734
rm -r MODEL
#1702654805
cd MODEL
#1702654808
module load gcc gsl
#1702654811
chmod 0700 ./compiler.sh 
#1702654813
./compiler.sh linesearch_mcmc
#1702654820
sbatch arrayjob.sbatch 
#1702654865
squeue --user=shorigan
#1702655811
cd ..
#1702655813
cd MODEL1
#1702655815
ls
#1702655819
module load gcc gsl
#1702655822
chmod 0700 ./compiler.sh 
#1702655824
./compiler.sh linesearch_mcmc
#1702655832
sbatch arrayjob.sbatch 
#1702655837
squeue --user=shorigan
#1702660056
scancel --user=shorigan
#1702660263
squeue --user=shorigan
#1702660303
cd ..
#1702660305
rm -r MODEL1
#1702660549
cd MODEL1
#1702660554
module load gcc gsl
#1702660558
chmod 0700 ./compiler.sh 
#1702660561
./compiler.sh linesearch_mcmc
#1702660570
./linesearch_mcmc 1 3 
#1702660741
cd ..
#1702660744
rm -r MODEL1
#1702660867
cd MODEL1
#1702660869
module load gcc gsl
#1702660872
chmod 0700 ./compiler.sh 
#1702660874
./linesearch_mcmc 1 3 
#1702660877
./compiler.sh linesearch_mcmc
#1702660881
./linesearch_mcmc 1 3 
#1702660959
cd ..
#1702660961
rm -r MODEL1
#1702660981
cd MODEL1
#1702660984
module load gcc gsl
#1702660987
chmod 0700 ./compiler.sh 
#1702660989
./compiler.sh linesearch_mcmc
#1702660993
./linesearch_mcmc 1 3 
#1702661037
cd ..
#1702661038
rm -r MODEL1
#1702661052
cd MODEL1
#1702661054
module load gcc gsl
#1702661057
chmod 0700 ./compiler.sh 
#1702661059
./compiler.sh linesearch_mcmc
#1702661064
./linesearch_mcmc 1 3 
#1702661087
cd ..
#1702661090
rm -r MODEL1
#1702661102
cd MODEL1
#1702661104
module load gcc gsl
#1702661107
chmod 0700 ./compiler.sh 
#1702661109
./compiler.sh linesearch_mcmc
#1702661113
./linesearch_mcmc 1 3 
#1702661447
cd ..
#1702661448
rm -r MODEL1
#1702661606
cd MODEL1
#1702661612
chmod 0700 ./compiler.sh 
#1702661614
./compiler.sh linesearch_mcmc
#1702661620
./linesearch_mcmc 1 3 
#1702661665
cd ..
#1702661667
rm -r MODEL1
#1702661688
cd MODEL1
#1702661694
chmod 0700 ./compiler.sh 
#1702661697
./compiler.sh linesearch_mcmc
#1702661701
./linesearch_mcmc 1 3 
#1702661761
cd ..
#1702661764
rm -r MODEL1
#1702661781
cd MODEL1
#1702661784
chmod 0700 ./compiler.sh 
#1702661787
./compiler.sh linesearch_mcmc
#1702661791
./linesearch_mcmc 1 3 
#1702661841
sbatch arrayjob.sbatch 
#1702661918
squeue --user=shorigan
#1702663955
sbatch arrayjob.sbatch 
#1702663965
scancel --user=shorigan
#1702664391
cd ..
#1702664394
rm -r MODEL1
#1702664433
cd MODEL1
#1702664441
chmod 0700 ./compiler.sh 
#1702664450
module load gcc gsl
#1702664453
./compiler.sh linesearch_mcmc
#1702664461
sbatch arrayjob.sbatch 
#1702665124
squeue --user=shorigan
#1702667530
scancel --user=shorigan
#1702667800
cd ..
#1702667802
rm -r MODEL1
#1702667829
cd MODEL1
#1702667837
module load gcc gsl
#1702667841
chmod 0700 ./compiler.sh 
#1702667846
./compiler.sh linesearch_mcmc
#1702667865
sbatch arrayjob.sbatch 
#1702668074
cd ..
#1702668078
squeue --user=shorigan
#1702668081
rm -r MODEL1
#1702668102
cd MODEL1
#1702668109
chmod 0700 ./compiler.sh 
#1702668111
./compiler.sh linesearch_mcmc
#1702668145
cd ..
#1702668146
rm -r MODEL
#1702668158
rm -r MODEL1
#1702668196
cd MODEL
#1702668198
chmod 0700 ./compiler.sh 
#1702668201
./compiler.sh linesearch_mcmc
#1702668342
cd ..
#1702668346
rm -r MODEL
#1702668364
cd MODEL
#1702668366
chmod 0700 ./compiler.sh 
#1702668367
./compiler.sh linesearch_mcmc
#1702668469
cd ..
#1702668470
rm -r MODEL
#1702668483
cd MODEL
#1702668485
chmod 0700 ./compiler.sh 
#1702668486
./compiler.sh linesearch_mcmc
#1702669416
cd ..
#1702669418
rm -r MODEL
#1702669438
cd MODEL
#1702669440
chmod 0700 ./compiler.sh 
#1702669442
./compiler.sh linesearch_mcmc
#1702669474
./linesearch_mcmc 1 3
#1702669528
sbatch arrayjob.sbatch 
#1702669827
squeue --user=shorigan
#1702670222
scancel --user=shorigan
#1702670249
cd ..
#1702670250
rm -r MODEL
#1702670278
cd MODEL
#1702670281
chmod 0700 ./compiler.sh 
#1702670284
./compiler.sh linesearch_mcmc
#1702670300
./linesearch_mcmc 1 3
#1702670346
cd ..
#1702670347
rm -r MODEL
#1702670359
cd MODEL
#1702670361
chmod 0700 ./compiler.sh 
#1702670363
./compiler.sh linesearch_mcmc
#1702670367
./linesearch_mcmc 1 3
#1702670447
cd ..
#1702670448
rm -r MDOEL
#1702670450
rm -r MODEL
#1702670476
cd MODEL
#1702670479
chmod 0700 ./compiler.sh 
#1702670483
./compiler.sh linesearch_mcmc
#1702670489
./linesearch_mcmc 1 3
#1702670564
cd ..
#1702670565
rm -r MODEL
#1702670579
cd MODEL
#1702670583
chmod 0700 ./compiler.sh 
#1702670585
./linesearch_mcmc 1 3
#1702670588
./compiler.sh linesearch_mcmc
#1702670593
./linesearch_mcmc 1 3
#1702670870
./compiler.sh linesearch_mcmc
#1702670873
./linesearch_mcmc 1 3
#1702671208
cd ..
#1702671211
rm -r MODEL
#1702671255
cd MODEL
#1702671262
chmod 0700 ./compiler.sh 
#1702671265
./compiler.sh linesearch_mcmc
#1702671281
sbatch arrayjob.sbatch 
#1702671453
scancel --user=shorigan
#1702671624
cd ..
#1702671626
rm -r MODEL
#1702671676
cd MODEL
#1702671678
chmod 0700 ./compiler.sh 
#1702671681
./compiler.sh linesearch_mcmc
#1702671695
sbatch arrayjob.sbatch 
#1702673561
squeue --user=shorigan
#1702673829
scancel --user=shorigan
#1702673835
ls
#1702673841
rm -r mcmc_results*
#1702673850
rm -r slurm-*
#1702673861
rm -r 'error*
'
#1702673873
rm -r error*
#1702673877
ls
#1702673923
cd ..
#1702673926
rm -r MODEL
#1702674092
cd MODEL
#1702674098
chmod 0700 ./compiler.sh 
#1702674103
./compiler.sh linesearch_mcmc
#1702674114
sbatch arrayjob.sbatch 
#1702674933
scancel --user=shorigan
#1702674935
cd ..
#1702674936
rm -r MODEL
#1702674983
cd MODEL
#1702674986
chmod 0700 ./compiler.sh 
#1702674988
./compiler.sh linesearch_mcmc
#1702674999
sbatch arrayjob.sbatch 
#1702675238
squeue --user=shorigan
#1702677133
cd ..
#1702677134
rm -r MODEL
#1702677185
cd MODEL
#1702677188
chmod 0700 ./compiler.sh 
#1702677191
./compiler.sh linesearch_mcmc
#1702677199
sbatch arrayjob.sbatch 
#1702677204
squeue --user=shorigan
#1702677238
scancel --job-id=3975088_100
#1702677243
scancel --help
#1702677254
scancel --name=3975088_100
#1702677261
scalcen --name= 3975088_15
#1702677268
scancel --name= 3975088_15
#1702677278
scancel --name=3975088_3
#1702677282
squeue --user=shorigan
#1702677888
cd ..
#1702677889
rm -r MODEL
#1702677930
cd MODEL
#1702677935
chmod 0700 ./compiler.sh 
#1702677939
./compiler.sh linesearch_mcmc
#1702677985
sbatch arrayjob.sbatch 
#1702678000
squeue --user=shorigan
#1702678006
scancel --user=shorigan
#1702678014
squeue --user=shorigan
#1702678018
sbatch arrayjob.sbatch 
#1702678022
squeue --user=shorigan
#1702678265
scancel --user=shorigan
#1702678275
cd ..
#1702678276
rm -r MODEL
#1702678358
cd MODEL
#1702678363
chmod 0700 ./compiler.sh 
#1702678366
./compiler.sh linesearch_mcmc
#1702678394
sbatch arrayjob.sbatch 
#1702678401
squeue --user=shorigan
#1702678511
scancel --user=shorigan
#1702678513
cd ..
#1702678515
rm -r MODEL
#1702678534
cd MODEL
#1702678553
chmod 0700 ./compiler.sh 
#1702678556
./compiler.sh linesearch_mcmc
#1702678574
sbatch arrayjob.sbatch 
#1702678688
cd ..
#1702678690
rm -r MODEL
#1702678752
cd MODEL
#1702678755
chmod 0700 ./compiler.sh 
#1702678756
./compiler.sh linesearch_mcmc
#1702678764
sbatch arrayjob.sbatch 
#1702678939
scancel --user=shorigan
#1702678941
cd ..
#1702678942
rm -r MODEL
#1702678966
cd MODEL
#1702678970
chmod 0700 ./compiler.sh 
#1702678972
./compiler.sh linesearch_mcmc
#1702678980
sbatch arrayjob.sbatch 
#1702679470
squeue --user=shorigan
#1702679480
scancel --user=shorigan
#1702679481
cd ..
#1702679483
rm -r MODEL
#1702679508
cd MODEL
#1702679511
chmod 0700 ./compiler.sh 
#1702679513
./compiler.sh linesearch_mcmc
#1702679522
sbatch arrayjob.sbatch 
#1702679622
scancel --user=shorigan
#1702679654
cd ..
#1702679657
rm -r MODEL
#1702679672
cd MODEL
#1702679675
chmod 0700 ./compiler.sh 
#1702679677
./compiler.sh linesearch_mcmc
#1702679681
sbatch arrayjob.sbatch 
#1702679723
cd ..
#1702679727
rm -r MODEL
#1702679810
scancel --user=shorigan
#1702679812
chmod 0700 ./compiler.sh 
#1702679831
cd MODEL
#1702679834
chmod 0700 ./compiler.sh 
#1702679837
./compiler.sh linesearch_mcmc
#1702679841
sbatch arrayjob.sbatch 
#1702679948
cd ..
#1702679950
rm -r MODEL
#1702679985
cd MODEL
#1702679990
chmod 0700 ./compiler.sh 
#1702679992
./compiler.sh linesearch_mcmc
#1702679996
sbatch arrayjob.sbatch 
#1702680060
scancel --user=shorigan
#1702680062
cd ..
#1702680063
rm -r MODEL
#1702680083
cd MODEL
#1702680085
chmod 0700 ./compiler.sh 
#1702680087
./compiler.sh linesearch_mcmc
#1702680091
sbatch arrayjob.sbatch 
#1702680134
scancel --user=shorigan
#1702680137
cd ..
#1702680138
rm -r MODEL
#1702680153
cd MODEL
#1702680155
chmod 0700 ./compiler.sh 
#1702680157
./compiler.sh linesearch_mcmc
#1702680161
sbatch arrayjob.sbatch 
#1702680248
cd ..
#1702680249
rm -r MODEL
#1702680270
cd MODEL
#1702680272
chmod 0700 ./compiler.sh 
#1702680274
./compiler.sh linesearch_mcmc
#1702680278
sbatch arrayjob.sbatch 
#1702680319
scancel --user=shorigan
#1702680322
cd ..
#1702680326
rm -r MODEL
#1702680347
cd MODEL
#1702680350
chmod 0700 ./compiler.sh 
#1702680352
./compiler.sh linesearch_mcmc
#1702680356
sbatch arrayjob.sbatch 
#1702680388
cd ..
#1702680390
rm -r MODEL
#1702680400
cd MODEL
#1702680402
chmod 0700 ./compiler.sh 
#1702680404
./compiler.sh linesearch_mcmc
#1702680408
sbatch arrayjob.sbatch 
#1702680502
scancel --user=shorigan
#1702680504
cd ..
#1702680507
rm -r MDOEL
#1702680509
rm -r MODEL
#1702680655
squeue --user=shorigan
#1704723900
cd MODEL
#1704723907
chmod 0700 ./compiler.sh 
#1704723920
module load gcc gsl
#1704723926
./compiler.sh linesearch_mcmc
#1704723933
sbatch arrayjob.sbatch 
#1704723937
squeue --user=shorigan
#1704724128
scancel --user=shorigan
#1704724608
cd ..
#1704724610
rm -r MODEL
#1704724618
sinteractive
#1704725454
ls
#1704725483
cd MODEL
#1704725489
chmod 0700 ./compiler.sh 
#1704725492
./compiler.sh linesearch_mcmc
#1704725498
sbatch arrayjob.sbatch 
#1704725504
squeue --user=shorigan
#1704725525
scancel --user=shorigan
#1704726171
cd ..
#1704726172
rm -r MODEL
#1704726227
cd MODEL
#1704726232
chmod 0700 ./compiler.sh 
#1704726236
./compiler.sh linesearch_mcmc
#1704726241
sbatch arrayjob.sbatch 
#1704726267
scancel --user=shorigan
#1704726539
cd ..
#1704726541
rm -r MODEL
#1704726561
cd MODEL
#1704726566
chmod 0700 ./compiler.sh 
#1704726568
./compiler.sh linesearch_mcmc
#1704726605
cd ..
#1704726606
rm -r MODEL
#1704726627
cd MODEL
#1704726629
chmod 0700 ./compiler.sh 
#1704726631
./compiler.sh linesearch_mcmc
#1704726637
sbatch arrayjob.sbatch 
#1704726658
scancel --user=shorigan
#1704728009
cd ..
#1704728011
rm -r MODEL
#1704728023
cd MODEL
#1704728027
chmod 0700 ./compiler.sh 
#1704728030
sbatch arrayjob.sbatch 
#1704728036
scancel --user=shorigan
#1704728069
./compiler.sh linesearch_mcmc
#1704728076
sbatch arrayjob.sbatch 
#1704728098
scancel --user=shorigan
#1704742207
ls
#1704742209
rm -r MODEL
#1704742226
cd MODEL
#1704742237
module load gcc gsl
#1704742243
module load gsl gxx
#1704742250
chmod 0700 ./compiler.sh 
#1704742253
./compiler.sh linesearch_mcmc
#1704742386
cd ..
#1704742388
rm -r MODEL
#1704742402
cd MODEL
#1704742404
chmod 0700 ./compiler.sh 
#1704742406
./compiler.sh linesearch_mcmc
#1704742418
sbatch arrayjob.sbatch 
#1704742423
squeue --user=shorigan
#1704742592
scancel --user=shorigan
#1704742598
cd ..
#1704742600
rm -r MODEL
#1704742889
cd MODEL
#1704742892
chmod 0700 ./compiler.sh 
#1704742895
./compiler.sh linesearch_mcmc
#1704742901
sbatch arrayjob.sbatch 
#1704742909
squeue --user=shorigan
#1704742988
scancel --user=shorigan
#1704743072
cd ..
#1704743074
rm -r MODEL
#1704743124
cd MODEL
#1704743127
chmod 0700 ./compiler.sh 
#1704743129
./compiler.sh linesearch_mcmc
#1704743134
sbatch arrayjob.sbatch 
#1704743230
scancel -user=shorigan
#1704743234
scancel --user=shorigan
#1704743456
cd ..
#1704743457
rm -r MODEL
#1704743540
cd MODEL
#1704743544
chmod 0700 ./compiler.sh 
#1704743546
./compiler.sh linesearch_mcmc
#1704743561
sbatch arrayjob.sbatch 
#1704743734
scancel --user=shorigan
#1704743772
cd ..
#1704743774
rm -r MODEL
#1704743790
cd MODEL
#1704743792
chmod 0700 ./compiler.sh 
#1704743794
./compiler.sh linesearch_mcmc
#1704743799
sbatch arrayjob.sbatch 
#1704743804
squeue --user=shorigan
#1704744544
scancel --user=shorigan
#1704744720
cd ..
#1704744721
rm -r MODEL
#1704744749
cd MODEL
#1704744753
chmod 0700 ./compiler.sh 
#1704744755
./compiler.sh linesearch_mcmc
#1704744760
sbatch arrayjob.sbatch 
#1704744766
squeue --user=shorigan
#1704772200
ls
#1704772202
rm -r MODEL
#1704772239
ls
#1704772241
cd MODEL
#1704772248
module load gcc gsl 
#1704772252
chmod 0700 ./compiler.sh 
#1704772254
./compiler.sh linesearch_mcmc
#1704772260
sbatch arrayjob.sbatch 
#1704809648
squeue --user=shorigan
#1704815074
rm -r MODEL
#1704815088
cd MODEL
#1704815092
module load gcc gsl 
#1704815094
chmod 0700 ./compiler.sh 
#1704815095
./compiler.sh linesearch_mcmc
#1704815101
sbatch arrayjob.sbatch 
#1704815105
squeue --user=shorigan
#1704824748
scancel --user=shorigan
#1704824754
rm -r MODEL
#1704825560
ls
#1704825676
cd MODEL
#1704825681
module load gcc gsl 
#1704825684
chmod 0700 ./compiler.sh 
#1704825686
./compiler.sh linesearch_mcmc
#1704825693
sbatch arrayjob.sbatch 
#1704838163
squeue --user=shorigan
#1704848363
scancel --user=shorigan
#1704848367
rm -r MODEL
#1704848380
ls
#1704848464
cd MODEL
#1704848467
module load gcc gsl 
#1704848470
chmod 0700 ./compiler.sh 
#1704848473
./compiler.sh linesearch_mcmc
#1704848480
sbatch arrayjob.sbatch 
#1704848484
squeue --user=shorigan
