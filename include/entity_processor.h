#pragma once

#include "file.h"
#include "comms/entity.pb.h"
#include <string>

class EntityProcessor{
	public:
	EntityProcessor(const FilePtr& file);
  EntityProcessor(const Entity& entity);
  EntityProcessor(const std::string serialized_data);
	std::string serialize() const;
  Entity getEntity() const;
  void printDescription() const;
	
	private:
  void createEntityWithChildren(const FilePtr& file);
  void createNestedEntity(const FilePtr& parentFile, Entity* parentEntity, int depth) const;
  void printNestedEntity(const Entity& entity, int depth = 0) const;
  Entity entity_;
};
