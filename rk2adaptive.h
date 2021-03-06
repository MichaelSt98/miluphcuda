/**
 * @author      Christoph Schaefer cm.schaefer@gmail.com
 *
 * @section     LICENSE
 * Copyright (c) 2019 Christoph Schaefer
 *
 * This file is part of miluphcuda.
 *
 * miluphcuda is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * miluphcuda is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with miluphcuda.  If not, see <http://www.gnu.org/licenses/>.
 *
 */


#ifndef _RK2ADAPTIVE_H
#define _RK2ADAPTIVE_H

#include "miluph.h"
#include "timeintegration.h"


void rk2Adaptive();


__global__ void limitTimestep(double *forcesPerBlock, double *courantPerBlock);

__global__ void checkError(
		double *maxPosAbsErrorPerBlock, double *maxVelAbsErrorPerBlock
#if INTEGRATE_DENSITY
		, double *maxDensityAbsErrorPerBlock
#endif
#if INTEGRATE_ENERGY
		, double *maxEnergyAbsErrorPerBlock
#endif
#if PALPHA_POROSITY
        , double *maxPressureAbsChangePerBlock
#endif
);

__global__ void damageMaxTimeStep(double *maxDamageTimeStepPerBlock);
__global__ void alphaMaxTimeStep(double *maxalphaDiffPerBlock);

__global__ void integrateFirstStep(void);
__global__ void integrateSecondStep(void);
__global__ void integrateThirdStep(void);





#endif
