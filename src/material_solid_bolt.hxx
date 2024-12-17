#ifndef MATERIAL_SOLID_BOLT_HPP_
#define MATERIAL_SOLID_BOLT_HPP_

#include "material_solid.hpp"

namespace material
{
	class MaterialBolt;
	using MaterialBoltPtr = std::shared_ptr< MaterialBolt >;
	using ConstMaterialBoltPtr = std::shared_ptr< const MaterialBolt >;
	
	MaterialBoltPtr CreateMaterialBolt(Tag materialTag, String grade, Scalar diameter);

	class MaterialBolt : public MaterialSolid, virtual public std::enable_shared_from_this<MaterialBolt>
	{
	public:
		virtual ~MaterialBolt() = default;

		static MaterialBoltPtr Create();
		MaterialBoltPtr GetPtr();
		ConstMaterialBoltPtr GetPtr() const;

		void SetGrade(String grade);
		void SetDiameter(Scalar diameter);

	protected:
		MaterialBolt();

		void UpdateProperties();

		Scalar T_ref{ 293.15 };
		Scalar p_ref{ 101325.0 };

		IPropertyStringPtr grade_{ nullptr };
		IPropertyScalarPtr diameter_{ nullptr };

		using std::enable_shared_from_this<MaterialBolt>::shared_from_this;
	};
} // namespace material

#endif /* MATERIAL_SOLID_BOLT_HPP_*/
