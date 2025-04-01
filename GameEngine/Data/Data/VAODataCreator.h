#ifndef DATA_VAO_DATA_CREATOR_CREATOR_H
#define DATA_VAO_DATA_CREATOR_CREATOR_H

#include <memory>
#include "VAOData.h"

namespace sge {
	class VAODataCreator {
	public:
		virtual std::shared_ptr<VAOData> CreateVAOData() = 0;
	};
};

#endif // DATA_VAO_DATA_CREATOR_CREATOR_H