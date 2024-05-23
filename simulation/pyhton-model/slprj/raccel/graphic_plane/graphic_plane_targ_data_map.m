    function targMap = targDataMap(),

    ;%***********************
    ;% Create Parameter Map *
    ;%***********************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 4;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc paramMap
        ;%
        paramMap.nSections           = nTotSects;
        paramMap.sectIdxOffset       = sectIdxOffset;
            paramMap.sections(nTotSects) = dumSection; %prealloc
        paramMap.nTotData            = -1;

        ;%
        ;% Auto data (rtP)
        ;%
            section.nData     = 8;
            section.data(8)  = dumData; %prealloc

                    ;% rtP.FlatEarthtoLLA_LL0
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP.CompareToConstant_const
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 2;

                    ;% rtP.CompareToConstant_const_lpgrzvb4zb
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 3;

                    ;% rtP.CompareToConstant_const_ln1vphan13
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 4;

                    ;% rtP.CompareToConstant_const_cuek01fcm1
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 5;

                    ;% rtP.CompareToConstant_const_ourdeuccjb
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 6;

                    ;% rtP.CompareToConstant_const_kcefi55u0t
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 7;

                    ;% rtP.FlatEarthtoLLA_psi
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 8;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtP.FlightGearPreconfigured6DoFAnimation_DestinationPort
                    section.data(1).logicalSrcIdx = 8;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section

            section.nData     = 43;
            section.data(43)  = dumData; %prealloc

                    ;% rtP.Packnet_fdmPacketforFlightGear_P8
                    section.data(1).logicalSrcIdx = 9;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP.SimulationPace_P1
                    section.data(2).logicalSrcIdx = 10;
                    section.data(2).dtTransOffset = 1;

                    ;% rtP.SimulationPace_P2
                    section.data(3).logicalSrcIdx = 11;
                    section.data(3).dtTransOffset = 2;

                    ;% rtP.SimulationPace_P3
                    section.data(4).logicalSrcIdx = 12;
                    section.data(4).dtTransOffset = 3;

                    ;% rtP.SimulationPace_P4
                    section.data(5).logicalSrcIdx = 13;
                    section.data(5).dtTransOffset = 4;

                    ;% rtP.PacketSize_Value
                    section.data(6).logicalSrcIdx = 14;
                    section.data(6).dtTransOffset = 5;

                    ;% rtP.Constant_Value
                    section.data(7).logicalSrcIdx = 15;
                    section.data(7).dtTransOffset = 6;

                    ;% rtP.x_Value
                    section.data(8).logicalSrcIdx = 16;
                    section.data(8).dtTransOffset = 7;

                    ;% rtP.y_Value
                    section.data(9).logicalSrcIdx = 17;
                    section.data(9).dtTransOffset = 8;

                    ;% rtP.Constant2_Value
                    section.data(10).logicalSrcIdx = 18;
                    section.data(10).dtTransOffset = 9;

                    ;% rtP.Constant1_Value
                    section.data(11).logicalSrcIdx = 19;
                    section.data(11).dtTransOffset = 10;

                    ;% rtP.Constant_Value_ah3sen0uqm
                    section.data(12).logicalSrcIdx = 20;
                    section.data(12).dtTransOffset = 11;

                    ;% rtP.Constant_Value_h3mh4e54un
                    section.data(13).logicalSrcIdx = 21;
                    section.data(13).dtTransOffset = 12;

                    ;% rtP.Constant_Value_jntboeoydz
                    section.data(14).logicalSrcIdx = 22;
                    section.data(14).dtTransOffset = 13;

                    ;% rtP.f_Value
                    section.data(15).logicalSrcIdx = 23;
                    section.data(15).dtTransOffset = 14;

                    ;% rtP.Bias_Bias
                    section.data(16).logicalSrcIdx = 24;
                    section.data(16).dtTransOffset = 15;

                    ;% rtP.Constant2_Value_krlazp4iwf
                    section.data(17).logicalSrcIdx = 25;
                    section.data(17).dtTransOffset = 16;

                    ;% rtP.Bias1_Bias
                    section.data(18).logicalSrcIdx = 26;
                    section.data(18).dtTransOffset = 17;

                    ;% rtP.Bias_Bias_l4mmzmheyi
                    section.data(19).logicalSrcIdx = 27;
                    section.data(19).dtTransOffset = 18;

                    ;% rtP.Gain_Gain
                    section.data(20).logicalSrcIdx = 28;
                    section.data(20).dtTransOffset = 19;

                    ;% rtP.Bias1_Bias_lwb2x0lz4t
                    section.data(21).logicalSrcIdx = 29;
                    section.data(21).dtTransOffset = 20;

                    ;% rtP.Constant_Value_bugcmhye3g
                    section.data(22).logicalSrcIdx = 30;
                    section.data(22).dtTransOffset = 21;

                    ;% rtP.Constant3_Value
                    section.data(23).logicalSrcIdx = 31;
                    section.data(23).dtTransOffset = 22;

                    ;% rtP.Constant_Value_a10nlnrpwn
                    section.data(24).logicalSrcIdx = 32;
                    section.data(24).dtTransOffset = 23;

                    ;% rtP.Constant1_Value_fipwkjv1k4
                    section.data(25).logicalSrcIdx = 33;
                    section.data(25).dtTransOffset = 24;

                    ;% rtP.Bias_Bias_ezzhbbeoze
                    section.data(26).logicalSrcIdx = 34;
                    section.data(26).dtTransOffset = 25;

                    ;% rtP.Constant2_Value_c1ysq1elqy
                    section.data(27).logicalSrcIdx = 35;
                    section.data(27).dtTransOffset = 26;

                    ;% rtP.Bias1_Bias_g3odia1kmy
                    section.data(28).logicalSrcIdx = 36;
                    section.data(28).dtTransOffset = 27;

                    ;% rtP.Bias_Bias_pz4bj2aggk
                    section.data(29).logicalSrcIdx = 37;
                    section.data(29).dtTransOffset = 28;

                    ;% rtP.Constant2_Value_lzvy0bomjv
                    section.data(30).logicalSrcIdx = 38;
                    section.data(30).dtTransOffset = 29;

                    ;% rtP.Bias1_Bias_k5af1gwgsv
                    section.data(31).logicalSrcIdx = 39;
                    section.data(31).dtTransOffset = 30;

                    ;% rtP.Constant1_Value_powldid0mm
                    section.data(32).logicalSrcIdx = 40;
                    section.data(32).dtTransOffset = 31;

                    ;% rtP.Bias_Bias_a2ngdjn3cn
                    section.data(33).logicalSrcIdx = 41;
                    section.data(33).dtTransOffset = 32;

                    ;% rtP.Constant2_Value_o503yjt3g1
                    section.data(34).logicalSrcIdx = 42;
                    section.data(34).dtTransOffset = 33;

                    ;% rtP.Bias1_Bias_beqlpqjuhh
                    section.data(35).logicalSrcIdx = 43;
                    section.data(35).dtTransOffset = 34;

                    ;% rtP.Bias_Bias_fj5p4fqtlh
                    section.data(36).logicalSrcIdx = 44;
                    section.data(36).dtTransOffset = 35;

                    ;% rtP.Gain_Gain_jlh2aj143k
                    section.data(37).logicalSrcIdx = 45;
                    section.data(37).dtTransOffset = 36;

                    ;% rtP.Bias1_Bias_f0n3qnphy4
                    section.data(38).logicalSrcIdx = 46;
                    section.data(38).dtTransOffset = 37;

                    ;% rtP.Constant1_Value_c1zfghbdbg
                    section.data(39).logicalSrcIdx = 47;
                    section.data(39).dtTransOffset = 38;

                    ;% rtP.z_Value
                    section.data(40).logicalSrcIdx = 48;
                    section.data(40).dtTransOffset = 39;

                    ;% rtP.gama_Value
                    section.data(41).logicalSrcIdx = 49;
                    section.data(41).dtTransOffset = 40;

                    ;% rtP.theta_Value
                    section.data(42).logicalSrcIdx = 50;
                    section.data(42).dtTransOffset = 41;

                    ;% rtP.psi_Value
                    section.data(43).logicalSrcIdx = 51;
                    section.data(43).dtTransOffset = 42;

            nTotData = nTotData + section.nData;
            paramMap.sections(3) = section;
            clear section

            section.nData     = 7;
            section.data(7)  = dumData; %prealloc

                    ;% rtP.Packnet_fdmPacketforFlightGear_P1
                    section.data(1).logicalSrcIdx = 52;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP.Packnet_fdmPacketforFlightGear_P2
                    section.data(2).logicalSrcIdx = 53;
                    section.data(2).dtTransOffset = 2;

                    ;% rtP.Packnet_fdmPacketforFlightGear_P3
                    section.data(3).logicalSrcIdx = 54;
                    section.data(3).dtTransOffset = 4;

                    ;% rtP.Packnet_fdmPacketforFlightGear_P4
                    section.data(4).logicalSrcIdx = 55;
                    section.data(4).dtTransOffset = 7;

                    ;% rtP.Packnet_fdmPacketforFlightGear_P5
                    section.data(5).logicalSrcIdx = 56;
                    section.data(5).dtTransOffset = 10;

                    ;% rtP.Packnet_fdmPacketforFlightGear_P6
                    section.data(6).logicalSrcIdx = 57;
                    section.data(6).dtTransOffset = 13;

                    ;% rtP.Packnet_fdmPacketforFlightGear_P7
                    section.data(7).logicalSrcIdx = 58;
                    section.data(7).dtTransOffset = 16;

            nTotData = nTotData + section.nData;
            paramMap.sections(4) = section;
            clear section


            ;%
            ;% Non-auto Data (parameter)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        paramMap.nTotData = nTotData;



    ;%**************************
    ;% Create Block Output Map *
    ;%**************************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 3;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc sigMap
        ;%
        sigMap.nSections           = nTotSects;
        sigMap.sectIdxOffset       = sectIdxOffset;
            sigMap.sections(nTotSects) = dumSection; %prealloc
        sigMap.nTotData            = -1;

        ;%
        ;% Auto data (rtB)
        ;%
            section.nData     = 8;
            section.data(8)  = dumData; %prealloc

                    ;% rtB.datymt25li
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% rtB.gdfxliypwc
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% rtB.dhvfuzmxio
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% rtB.kgzgt0fmwb
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% rtB.fyvanjft0r
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

                    ;% rtB.piczck40ik
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 5;

                    ;% rtB.iz4nmuuwka
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 6;

                    ;% rtB.bsnqbjvtek
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 7;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% rtB.hoiago1axe
                    section.data(1).logicalSrcIdx = 8;
                    section.data(1).dtTransOffset = 0;

                    ;% rtB.ol3rikcdfs
                    section.data(2).logicalSrcIdx = 9;
                    section.data(2).dtTransOffset = 1;

                    ;% rtB.pipaywda1d
                    section.data(3).logicalSrcIdx = 10;
                    section.data(3).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            sigMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtB.a23sv4sybs
                    section.data(1).logicalSrcIdx = 11;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(3) = section;
            clear section


            ;%
            ;% Non-auto Data (signal)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        sigMap.nTotData = nTotData;



    ;%*******************
    ;% Create DWork Map *
    ;%*******************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 2;
        sectIdxOffset = 3;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc dworkMap
        ;%
        dworkMap.nSections           = nTotSects;
        dworkMap.sectIdxOffset       = sectIdxOffset;
            dworkMap.sections(nTotSects) = dumSection; %prealloc
        dworkMap.nTotData            = -1;

        ;%
        ;% Auto data (rtDW)
        ;%
            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% rtDW.ogbwgfogay
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.fs3gqwtfzy
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.ik244sfmwe
                    section.data(1).logicalSrcIdx = 2;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section


            ;%
            ;% Non-auto Data (dwork)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        dworkMap.nTotData = nTotData;



    ;%
    ;% Add individual maps to base struct.
    ;%

    targMap.paramMap  = paramMap;
    targMap.signalMap = sigMap;
    targMap.dworkMap  = dworkMap;

    ;%
    ;% Add checksums to base struct.
    ;%


    targMap.checksum0 = 2582406175;
    targMap.checksum1 = 1527522671;
    targMap.checksum2 = 249056648;
    targMap.checksum3 = 1448194977;

