This ReadMe provides a detailed description of all files and content that make up the data and model within this folder.

OVERVIEW
---------------------
-single-epizootic fungus-virus model with coinfection
-metapopulation structure with subpopulations
-dispersal between subpopulations
    -larval dispersal based on wind and distance
    -conidia dispersal based on distance


DATA
--------------------
Collected by Sophia Horigan in Southwestern Michigan in summer 2021. Features 6 different epizootic datasets, 1 weather dataset, 3 distance datasets, 3 dispersal probability datasets.

    Epizootic Data
    --------------------
    Data of counts of infection over time throughout an epizootic. Three experimental datasets, 3 observational datasets. All files (DATA_X.txt) in same format.
    Epizootic length for each dataset is 48 days (48 rows of content)
    Columns: S V F VF
        S: susceptble (no infection)
        V: virus-infected
        F: fungus-infected (resting spore or conidia)
        VF: coinfected with both virus and fungus
    -1 corresponds to days without collection, used for likelihood calculation in lhood_meta

        Experimental Data
        -----------------
        Experiments set up with 3 blocks, 4 treatments each. These represent the three metapopulations with 4 subpopulations each.
        Subpopulation Treatments:
            1. Virus-only
            2. Fungus-only
            3. Fungus-Virus
            4. Control
        Subpopuation data concatenated, such that, for example, rows:
        1-48: subpop 1 daily data
        48-96: subpop 2 daily data
        96-144: subpop 3 daily data
        144-192: subpop 4 daily data

            Files
            -----------------
            DATA_1.txt : Block 1 of experimental epizootic at KBS
            DATA_2.txt : Block 2 of experimental epizootic at KBS
            DATA_3.txt : Block 3 of experimental epizootic at KBS*          *may be called block 4 in associated content. had originally set up 4 blocks, block 3 failed, eventually renamed block 4 to block 3 for ease of indexing.

        Observational Data
        ------------------
        Epizootic data collected from three observational sites near experimental sites. No treatmenets, no subpopulations. In code, metapopulations without subpopulations.

            Files
            -----------------
            DATA_4.txt : JHN
            DATA_5.txt : ROB
            DATA_6.txt : YSN

    Weather Data
    ------------------
    Originally collected weather at three stations across field site, but 
