/* +---------------------------------------------------------------------------+
   |                     Mobile Robot Programming Toolkit (MRPT)               |
   |                          http://www.mrpt.org/                             |
   |                                                                           |
   | Copyright (c) 2005-2014, Individual contributors, see AUTHORS file        |
   | See: http://www.mrpt.org/Authors - All rights reserved.                   |
   | Released under BSD License. See details in http://www.mrpt.org/License    |
   +---------------------------------------------------------------------------+ */
#ifndef CRobotPosesGraph_H
#define CRobotPosesGraph_H

#include <mrpt/utils/CSerializable.h>

#include <mrpt/hmtslam/HMT_SLAM_common.h>
#include <mrpt/poses/CPose3DPDFParticles.h>
#include <mrpt/slam/CSensoryFrame.h>
#include <mrpt/slam/CSimpleMap.h>
#include <mrpt/slam/CMultiMetricMap.h>


namespace mrpt
{
	namespace hmtslam
	{
		using namespace mrpt::slam;

		/** Information kept for each robot pose used in CRobotPosesGraph */
		struct HMTSLAM_IMPEXP TPoseInfo
		{
			CSensoryFrame			sf;   //!< The observations
			CPose3DPDFParticles		pdf;  //!< The robot pose PDF
		};

		DEFINE_SERIALIZABLE_PRE_CUSTOM_BASE_LINKAGE( CRobotPosesGraph, mrpt::utils::CSerializable, HMTSLAM_IMPEXP )

		/** Auxiliary class used in mrpt::slam::CLocalMetricHypothesis for HMT-SLAM; this class stores a set of robot poses and its sensory frames and pose PDF, for being stored in a HMT-map as a serializable object in annotation NODE_ANNOTATION_POSES_GRAPH.
		  * \ingroup mrpt_hmtslam_grp
		  */
		class HMTSLAM_IMPEXP CRobotPosesGraph : public  mrpt::utils::CSerializable, public std::map<TPoseID,TPoseInfo>
		{
			// This must be added to any CSerializable derived class:
			DEFINE_SERIALIZABLE( CRobotPosesGraph )
		public:

			/** Insert all the observations in the map (without erasing previous contents). */
			void insertIntoMetricMap( CMultiMetricMap	&metricMap ) const;

			/** Converts the contents of this object into a 'simplemap' (mrpt::slam::CSimpleMap) object. */
			void convertIntoSimplemap( CSimpleMap &out_simplemap) const;

		}; // end of class


	} // End of namespace
} // End of namespace
#endif
