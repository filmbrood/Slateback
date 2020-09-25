#pragma once
#include <string>
#include <cereal/cereal.hpp>

// Data class for details regarding shot objects, which are contained within the Roll class as pointers in vector.
class Shot
{
public:
	Shot() {}
	~Shot() {}

public:
	void SetScene(std::string scene);
	void SetTake(std::string take);
	void SetFPS(std::string fps);
	void SetLens(std::string lens);
	void SetFStop(std::string fstop);
	void SetISO(std::string iso);
	void SetColorTemp(std::string colortemp);
	void SetFilter(std::string filter);

	std::string GetScene();
	std::string GetTake();
	std::string GetFPS();
	std::string GetLens();
	std::string GetFStop();
	std::string GetISO();
	std::string GetColorTemp();
	std::string GetFilter();

	// Serializes data using Cereal library
	template<class Archive>
	void serialize(Archive& archive);

private:

	std::string m_Scene;
	std::string m_Take;
	std::string m_FPS;
	std::string m_Lens;
	std::string m_FStop;
	std::string m_ISO;
	std::string m_ColorTemp;
	std::string m_Filter;
};

template<class Archive>
inline void Shot::serialize(Archive& archive)
{
	archive(CEREAL_NVP(m_Scene), CEREAL_NVP(m_Take), CEREAL_NVP(m_FPS), CEREAL_NVP(m_Lens), CEREAL_NVP(m_FStop), CEREAL_NVP(m_ISO), CEREAL_NVP(m_ColorTemp), CEREAL_NVP(m_Filter));
}
