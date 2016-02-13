#ifndef PATTERNRECOALGORITHM_H
#define PATTERNRECOALGORITHM_H

class QWidget;

class PatternRecoAlgorithm
{
public:
    PatternRecoAlgorithm();

    QWidget * getControlsWidget();

    int process();
};

#endif // PATTERNRECOALGORITHM_H
