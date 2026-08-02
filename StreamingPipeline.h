#ifndef STREAMING_PIPELINE_H
#define STREAMING_PIPELINE_H

#include "Pipeline.h"

class StreamingPipeline : public Pipeline {
public:
    StreamingPipeline(ConnectorFactory* factory);
    void extract() override;
    void load() override;
};

#endif