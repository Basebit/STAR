#ifndef H_SoloReadFeature
#define H_SoloReadFeature
#include <set>
#include <map>
#include "IncludeDefine.h"
#include "Parameters.h"
#include "Transcript.h"
#include "SoloReadBarcode.h"
#include "SoloCommon.h"
#include "SoloReadFeatureStats.h"
#include "ReadAnnotations.h"

class SoloFeature;

class SoloReadFeature {
public:

    uint32 homoPolymer[4];//homopolymer constants

    uint32 *cbReadCount;
    map <uint32,uint32> cbReadCountMap;
    
    bool readInfoYes;

    fstream *streamReads;

    string cbSeq, umiSeq, cbQual, umiQual;
    
    SoloReadFeatureStats stats;

    SoloReadFeature (int32 feTy, Parameters &Pin, int iChunk);
    void record(SoloReadBarcode &soloBar, uint nTr, Transcript *alignOut, uint64 iRead, ReadAnnotations &readAnnot);
    void addCounts(const SoloReadFeature &soloCBin);
    void addStats(const SoloReadFeature &soloCBin);
    void statsOut(ofstream &streamOut);
    void inputRecords(uint32 **cbP, uint32 cbPstride, uint32 *cbReadCountExact, 
                      ofstream *streamTranscriptsOut, vector<readInfoStruct> &readInfo, SoloFeature **soloFeatAll);

private:
    const int32 featureType;

    Parameters &P;
    ParametersSolo &pSolo;
};

#endif
