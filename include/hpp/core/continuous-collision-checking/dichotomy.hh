//
// Copyright (c) 2014 CNRS
// Authors: Florent Lamiraux
//
// This file is part of hpp-core
// hpp-core is free software: you can redistribute it
// and/or modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation, either version
// 3 of the License, or (at your option) any later version.
//
// hpp-core is distributed in the hope that it will be
// useful, but WITHOUT ANY WARRANTY; without even the implied warranty
// of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Lesser Public License for more details.  You should have
// received a copy of the GNU Lesser General Public License along with
// hpp-core  If not, see
// <http://www.gnu.org/licenses/>.

#ifndef HPP_CORE_CONTINUOUS_COLLISION_CHECKING_DICHOTOMY_HH
# define HPP_CORE_CONTINUOUS_COLLISION_CHECKING_DICHOTOMY_HH

# include <hpp/core/path-validation.hh>

namespace hpp {
  namespace core {
    namespace continuousCollisionChecking {
      namespace dichotomy {
	HPP_PREDEF_CLASS (BodyPairCollision);
	typedef boost::shared_ptr <BodyPairCollision> BodyPairCollisionPtr_t;
	typedef std::list <BodyPairCollisionPtr_t> BodyPairCollisions_t;
      }
      using dichotomy::BodyPairCollisions_t;
      /// Continuous validation of a path for collision
      class HPP_CORE_DLLAPI Dichotomy : public PathValidation
      {
      public:
	/// Create instance and return shared pointer
	/// \param robot the robot for which collision checking is performed,
	/// \param tolerance maximal penetration allowed.
	static DichotomyPtr_t
	  create (const DevicePtr_t& robot, const value_type& tolerance);
	/// Compute the biggest valid interval starting from the path beginning
	///
	/// \param path the path to check for validity,
	/// \param reverse if true check from the end,
	/// \retval the extracted valid part of the path, pointer to path if
	///         path is valid.
	/// \return whether the whole path is valid.
	virtual bool validate (const PathPtr_t& path, bool reverse,
			       PathPtr_t& validPart);
	
	/// Add an obstacle
	/// \param object obstacle added
	/// Add the object to each collision pair a body of which is the
	/// environment.
	/// care about obstacles.
	virtual void addObstacle (const CollisionObjectPtr_t& object);
	
	virtual ~Dichotomy ();
      protected:
	/// Constructor
	/// \param robot the robot for which collision checking is performed,
	/// \param tolerance maximal penetration allowed.
	Dichotomy (const DevicePtr_t& robot,
		   const value_type& tolerance);
      private:
	DevicePtr_t robot_;
	value_type tolerance_;
	dichotomy::BodyPairCollisions_t bodyPairCollisions_;
      }; // class Dichotomy
    } // namespace continuousCollisionChecking
  } // namespace core
} // namespace hpp
#endif // HPP_CORE_CONTINUOUS_COLLISION_CHECKING_DICHOTOMY_HH