//composite_encoder.h, Matthew Ferguson, 11/10/2023
//Composite encoder implementation

#include "composite_encoder.h"

//iterate through components and call their encode methods
QString CompositeEncoder::encode(const QString & data) {
    QString encodedData = data;
    for (const auto& encoder : encoders) {
        encodedData = encoder->encode(encodedData);
    }
    return encodedData;
}

//iterate through components in reverse order and call their decode methods
QString CompositeEncoder::decode(const QString & data) {
    QString decodedData = data;
    for (int i = encoders.size() - 1; i >= 0; --i) {
        decodedData = encoders[i]->decode(decodedData);
    }
    return decodedData;
}
