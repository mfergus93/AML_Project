//composite_encoder.h, Matthew Ferguson, 11/10/2023
//Composite Encoder class implementation

#ifndef COMPOSITE_ENCODER_H
#define COMPOSITE_ENCODER_H

#include "encoder.h" // Include the abstract class
#include <vector>
#include <memory>

class CompositeEncoder : public Encoder {
public:
    CompositeEncoder() {} // Constructor

    //add components to our compsoite encoder
    void addEncoder(std::shared_ptr<Encoder> encoder, const QString& componentName) {
        encoders.push_back(encoder);
        components.push_back({encoder, componentName});
    }

    QString encode(const QString& data) override;
    QString decode(const QString& data) override;

    //allow access to components
    const std::vector<std::pair<std::shared_ptr<Encoder>, QString>>& getComponents() const {
        return components;
    }
private:
        //data structure of encoders
        std::vector<std::shared_ptr<Encoder>> encoders;
        std::vector<std::pair<std::shared_ptr<Encoder>, QString>> components;
};


#endif // COMPOSITE_ENCODER_H
