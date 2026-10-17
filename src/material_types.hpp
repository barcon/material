#ifndef MATERIAL_TYPES_HPP_
#define MATERIAL_TYPES_HPP_

#include "eilig.hpp"
#include "value.hpp"

#include <memory>
#include <variant>
#include <unordered_map>

namespace material
{
	using namespace eilig;
	using namespace value;

	using Properties = std::unordered_map<String, IValuePtr>;

	const String headerMaterial = "MATERIAL";

	enum class MaterialType
	{
		solid = 1,
		fluid = 2
	};

} // namespace material

#endif /* MATERIAL_TYPES_HPP_*/