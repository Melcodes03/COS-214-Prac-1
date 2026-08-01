#ifndef BATCHPIPELINE_H
#define BATCHPIPELINE_H

#include "Pipeline.h"

class BatchPipeline : public Pipeline {
public:
    BatchPipeline(ConnectorFactory* factory);

protected:
    void extract() override;
    void load() override;
};

#endif
