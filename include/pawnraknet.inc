/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2017 urShadow
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#if !defined PAWNRAKNET_INC_
    #define PAWNRAKNET_INC_

    #define PAWNRAKNET_INCLUDE_VERSION 102

    enum PR_HandlerType
    {
        PR_INCOMING_RPC,
        PR_INCOMING_PACKET,
        PR_OUTCOMING_RPC,
        PR_OUTCOMING_PACKET,
        PR_NUMBER_OF_HANDLER_TYPES
    };

    enum PR_ValueType
    {
        PR_INT8,
        PR_INT16,
        PR_INT32,
        PR_UINT8,
        PR_UINT16,
        PR_UINT32,
        PR_FLOAT,
        PR_BOOL,
        PR_STRING,

        // compressed
        PR_CINT8,
        PR_CINT16,
        PR_CINT32,
        PR_CUINT8,
        PR_CUINT16,
        PR_CUINT32,
        PR_CFLOAT,
        PR_CBOOL,
        PR_CSTRING,

        PR_BITS
    };

    enum PR_PacketPriority
    {
        PR_SYSTEM_PRIORITY,
        PR_HIGH_PRIORITY,
        PR_MEDIUM_PRIORITY,
        PR_LOW_PRIORITY
    };

    enum PR_PacketReliability
    {
        PR_UNRELIABLE = 6,
        PR_UNRELIABLE_SEQUENCED,
        PR_RELIABLE,
        PR_RELIABLE_ORDERED,
        PR_RELIABLE_SEQUENCED
    };

    #if !defined __cplusplus
        public _pawnraknet_version = PAWNRAKNET_INCLUDE_VERSION;
        #pragma unused _pawnraknet_version

        public bool:_pawnraknet_is_gamemode = !defined FILTERSCRIPT;
        #pragma unused _pawnraknet_is_gamemode

        #define IRPC:%0(%1) \
        forward pr_rir_%0(); \
        public pr_rir_%0() \
            PR_RegHandler(%0, "pr_ir_"#%0, PR_INCOMING_RPC); \
        forward pr_ir_%0(%1); \
        public pr_ir_%0(%1)

        #define IPacket:%0(%1) \
        forward pr_rip_%0(); \
        public pr_rip_%0() \
            PR_RegHandler(%0, "pr_ip_"#%0, PR_INCOMING_PACKET); \
        forward pr_ip_%0(%1); \
        public pr_ip_%0(%1)

        #define ORPC:%0(%1) \
        forward pr_ror_%0(); \
        public pr_ror_%0() \
            PR_RegHandler(%0, "pr_or_"#%0, PR_OUTCOMING_RPC); \
        forward pr_or_%0(%1); \
        public pr_or_%0(%1)

        #define OPacket:%0(%1) \
        forward pr_rop_%0(); \
        public pr_rop_%0() \
            PR_RegHandler(%0, "pr_op_"#%0, PR_OUTCOMING_PACKET); \
        forward pr_op_%0(%1); \
        public pr_op_%0(%1)

        #define IncomingRPC IRPC
        #define OutcomingRPC ORPC
        #define IncomingPacket IPacket
        #define OutcomingPacket OPacket

        enum RAKNET_ONFOOT_SYNC
        {
            PR_lrKey,
            PR_udKey,
            PR_keys,
            Float: RAKNET_POS_X,
			Float: RAKNET_POS_Y,
			Float: RAKNET_POS_Z,
            Float: RAKNET_QUAT_X,
			Float: RAKNET_QUAT_Y,
			Float: RAKNET_QUAT_Z,
			Float: RAKNET_QUAT_R,
            PR_health,
            PR_armour,
            RAKNET_WEAPON,
            PR_additionalKey,
            RAKNET_ACTION,
            Float:RAKNET_SPEED_X,
			Float:RAKNET_SPEED_Y,
			Float:RAKNET_SPEED_Z,
            Float:PR_surfingOffsets[3],
            PR_surfingVehicleId,
            RAKNET_ANIM,
            PR_animationFlags
        };

        enum RAKNET_DRIVER_SYNC
        {
            RAKNET_VEHICLE,
            PR_lrKey,
            PR_udKey,
            PR_keys,
            Float: RAKNET_QUAT_X,
			Float: RAKNET_QUAT_Y,
			Float: RAKNET_QUAT_Z,
			Float: RAKNET_QUAT_R,
            Float: RAKNET_POS_X,
			Float: RAKNET_POS_Y,
			Float: RAKNET_POS_Z,
            Float:RAKNET_SPEED_X,
			Float:RAKNET_SPEED_Y,
			Float:RAKNET_SPEED_Z,
            Float:PR_vehicleHealth,
            PR_playerHealth,
            PR_armour,
            PR_weaponId,
            PR_additionalKey,
            PR_sirenState,
            PR_landingGearState,
            PR_trailerId,
            Float:PR_trainSpeed
        };

        enum PR_TrailerSync
        {
            PR_trailerId,
            Float: RAKNET_POS_X,
			Float: RAKNET_POS_Y,
			Float: RAKNET_POS_Z,
            Float: RAKNET_QUAT_X,
			Float: RAKNET_QUAT_Y,
			Float: RAKNET_QUAT_Z,
			Float: RAKNET_QUAT_R,
            Float:RAKNET_SPEED_X,
			Float:RAKNET_SPEED_Y,
			Float:RAKNET_SPEED_Z,
            Float:PR_angularVelocity[3]
        };

        enum RAKNET_PASSENGER_SYNC
        {
            RAKNET_VEHICLE,
            PR_seatId,
            PR_driveBy,
            PR_weaponId,
            PR_additionalKey,
            PR_playerHealth,
            PR_playerArmour,
            PR_lrKey,
            PR_udKey,
            PR_keys,
            Float: RAKNET_POS_X,
			Float: RAKNET_POS_Y,
			Float: RAKNET_POS_Z,
        };

        enum PR_UnoccupiedSync
        {
            RAKNET_VEHICLE,
            PR_seatId,
            Float:PR_roll[3],
            Float:PR_direction[3],
            Float: RAKNET_POS_X,
			Float: RAKNET_POS_Y,
			Float: RAKNET_POS_Z,
            Float:RAKNET_SPEED_X,
			Float:RAKNET_SPEED_Y,
			Float:RAKNET_SPEED_Z,
            Float:PR_angularVelocity[3],
            Float:PR_vehicleHealth
        };

        enum PR_AimSync
        {
            PR_camMode,
            Float:PR_camFrontVec[3],
            Float:PR_camPos[3],
            Float:PR_aimZ,
            PR_camZoom,
            PR_weaponState,
            PR_aspectRatio
        };
        /*
         * RPC list: https://github.com/P3ti/RakSAMP/blob/master/raknet/SAMP/SAMPRPC.cpp
         * Packet list: https://github.com/P3ti/RakSAMP/blob/master/raknet/PacketEnumerations.h
         *
         * playerid == -1 => send to all players (broadcast)
         */

        native BS_RPC(BitStream:bs, playerid, rpcid, PR_PacketPriority:priority = PR_HIGH_PRIORITY, PR_PacketReliability:reliability = PR_RELIABLE_ORDERED);
        native BS_Send(BitStream:bs, playerid, PR_PacketPriority:priority = PR_HIGH_PRIORITY, PR_PacketReliability:reliability = PR_RELIABLE_ORDERED);

        native BitStream:BS_New();
        native BS_Delete(&BitStream:bs);

        native BS_Reset(BitStream:bs);
        native BS_ResetReadPointer(BitStream:bs);
        native BS_ResetWritePointer(BitStream:bs);
        native BS_IgnoreBits(BitStream:bs, number_of_bits);

        native BS_SetWriteOffset(BitStream:bs, offset);
        native BS_GetWriteOffset(BitStream:bs, &offset);
        native BS_SetReadOffset(BitStream:bs, offset);
        native BS_GetReadOffset(BitStream:bs, &offset);

        native BS_GetNumberOfBitsUsed(BitStream:bs, &number);
        native BS_GetNumberOfBytesUsed(BitStream:bs, &number);
        native BS_GetNumberOfUnreadBits(BitStream:bs, &number);

        native BS_WriteValue(BitStream:bs, {PR_ValueType, Float, _}:...);
        native BS_ReadValue(BitStream:bs, {PR_ValueType, Float, _}:...);

        #define BS_ReadInt8(%0,%1) BS_ReadValue(%0, PR_INT8, %1)
        #define BS_ReadInt16(%0,%1) BS_ReadValue(%0, PR_INT16, %1)
        #define BS_ReadInt32(%0,%1) BS_ReadValue(%0, PR_INT32, %1)
        #define BS_ReadUint8(%0,%1) BS_ReadValue(%0, PR_UINT8, %1)
        #define BS_ReadUint16(%0,%1) BS_ReadValue(%0, PR_UINT16, %1)
        #define BS_ReadUint32(%0,%1) BS_ReadValue(%0, PR_UINT32, %1)
        #define BS_ReadFloat(%0,%1) BS_ReadValue(%0, PR_FLOAT, %1)
        #define BS_ReadBool(%0,%1) BS_ReadValue(%0, PR_BOOL, %1)
        #define BS_ReadString(%0,%1,%2) BS_ReadValue(%0, PR_STRING, %1, %2)

        #define BS_ReadCompressedInt8(%0,%1) BS_ReadValue(%0, PR_CINT8, %1)
        #define BS_ReadCompressedInt16(%0,%1) BS_ReadValue(%0, PR_CINT16, %1)
        #define BS_ReadCompressedInt32(%0,%1) BS_ReadValue(%0, PR_CINT32, %1)
        #define BS_ReadCompressedUint8(%0,%1) BS_ReadValue(%0, PR_CUINT8, %1)
        #define BS_ReadCompressedUint16(%0,%1) BS_ReadValue(%0, PR_CUINT16, %1)
        #define BS_ReadCompressedUint32(%0,%1) BS_ReadValue(%0, PR_CUINT32, %1)
        #define BS_ReadCompressedFloat(%0,%1) BS_ReadValue(%0, PR_CFLOAT, %1)
        #define BS_ReadCompressedBool(%0,%1) BS_ReadValue(%0, PR_CBOOL, %1)
        #define BS_ReadCompressedString(%0,%1,%2) BS_ReadValue(%0, PR_CSTRING, %1, %2)

        #define BS_ReadBits(%0,%1,%2) BS_ReadValue(%0, PR_BITS, %1, %2)

        #define BS_WriteInt8(%0,%1) BS_WriteValue(%0, PR_INT8, %1)
        #define BS_WriteInt16(%0,%1) BS_WriteValue(%0, PR_INT16, %1)
        #define BS_WriteInt32(%0,%1) BS_WriteValue(%0, PR_INT32, %1)
        #define BS_WriteUint8(%0,%1) BS_WriteValue(%0, PR_UINT8, %1)
        #define BS_WriteUint16(%0,%1) BS_WriteValue(%0, PR_UINT16, %1)
        #define BS_WriteUint32(%0,%1) BS_WriteValue(%0, PR_UINT32, %1)
        #define BS_WriteFloat(%0,%1) BS_WriteValue(%0, PR_FLOAT, %1)
        #define BS_WriteBool(%0,%1) BS_WriteValue(%0, PR_BOOL, %1)
        #define BS_WriteString(%0,%1) BS_WriteValue(%0, PR_STRING, %1)

        #define BS_WriteCompressedInt8(%0,%1) BS_WriteValue(%0, PR_CINT8, %1)
        #define BS_WriteCompressedInt16(%0,%1) BS_WriteValue(%0, PR_CINT16, %1)
        #define BS_WriteCompressedInt32(%0,%1) BS_WriteValue(%0, PR_CINT32, %1)
        #define BS_WriteCompressedUint8(%0,%1) BS_WriteValue(%0, PR_CUINT8, %1)
        #define BS_WriteCompressedUint16(%0,%1) BS_WriteValue(%0, PR_CUINT16, %1)
        #define BS_WriteCompressedUint32(%0,%1) BS_WriteValue(%0, PR_CUINT32, %1)
        #define BS_WriteCompressedFloat(%0,%1) BS_WriteValue(%0, PR_CFLOAT, %1)
        #define BS_WriteCompressedBool(%0,%1) BS_WriteValue(%0, PR_CBOOL, %1)
        #define BS_WriteCompressedString(%0,%1) BS_WriteValue(%0, PR_CSTRING, %1)

        #define BS_WriteBits(%0,%1,%2) BS_WriteValue(%0, PR_BITS, %1, %2)

        stock BS_ReadOnFootSync(BitStream:bs, data[RAKNET_ONFOOT_SYNC])
        {
            BS_ReadValue(
                bs,
                PR_UINT16, data[PR_lrKey],
                PR_UINT16, data[PR_udKey],
                PR_UINT16, data[PR_keys],
				
                PR_FLOAT, data[RAKNET_POS_X],
                PR_FLOAT, data[RAKNET_POS_Y],
                PR_FLOAT, data[RAKNET_POS_Z],
				
                PR_FLOAT, data[RAKNET_QUAT_X],
                PR_FLOAT, data[RAKNET_QUAT_Y],
                PR_FLOAT, data[RAKNET_QUAT_Z],
                PR_FLOAT, data[RAKNET_QUAT_R],
				
                PR_UINT8, data[PR_health],
                PR_UINT8, data[PR_armour],
                PR_BITS, data[PR_additionalKey], 2,
                PR_BITS, data[RAKNET_WEAPON], 6,
                PR_UINT8, data[RAKNET_ACTION],
				
                PR_FLOAT, data[RAKNET_SPEED_X],
                PR_FLOAT, data[RAKNET_SPEED_Y],
                PR_FLOAT, data[RAKNET_SPEED_Z],
				
                PR_FLOAT, data[PR_surfingOffsets][0],
                PR_FLOAT, data[PR_surfingOffsets][1],
                PR_FLOAT, data[PR_surfingOffsets][2],
                PR_UINT16, data[PR_surfingVehicleId],
                PR_INT16, data[RAKNET_ANIM],
                PR_INT16, data[PR_animationFlags]
            );
        }

        stock BS_ReadInCarSync(BitStream:bs, data[RAKNET_DRIVER_SYNC])
        {
            BS_ReadValue(
                bs,
                PR_UINT16, data[RAKNET_VEHICLE],
                PR_UINT16, data[PR_lrKey],
                PR_UINT16, data[PR_udKey],
                PR_UINT16, data[PR_keys],
                PR_FLOAT, data[RAKNET_QUAT_X],
                PR_FLOAT, data[RAKNET_QUAT_Y],
                PR_FLOAT, data[RAKNET_QUAT_Z],
                PR_FLOAT, data[RAKNET_QUAT_R],
                PR_FLOAT, data[RAKNET_POS_X],
                PR_FLOAT, data[RAKNET_POS_Y],
                PR_FLOAT, data[RAKNET_POS_Z],
                PR_FLOAT, data[RAKNET_SPEED_X],
                PR_FLOAT, data[RAKNET_SPEED_Y],
                PR_FLOAT, data[RAKNET_SPEED_Z],
                PR_FLOAT, data[PR_vehicleHealth],
                PR_UINT8, data[PR_playerHealth],
                PR_UINT8, data[PR_armour],
                PR_BITS, data[PR_additionalKey], 2,
                PR_BITS, data[PR_weaponId], 6,
                PR_UINT8, data[PR_sirenState],
                PR_UINT8, data[PR_landingGearState],
                PR_UINT16, data[PR_trailerId],
                PR_FLOAT, data[PR_trainSpeed]
            );
        }

        stock BS_ReadTrailerSync(BitStream:bs, data[PR_TrailerSync])
        {
            BS_ReadValue(
                bs,
                PR_UINT16, data[PR_trailerId],
                PR_FLOAT, data[RAKNET_POS_X],
                PR_FLOAT, data[RAKNET_POS_Y],
                PR_FLOAT, data[RAKNET_POS_Z],
                PR_FLOAT, data[RAKNET_QUAT_X],
                PR_FLOAT, data[RAKNET_QUAT_Y],
                PR_FLOAT, data[RAKNET_QUAT_Z],
                PR_FLOAT, data[RAKNET_QUAT_R],
                PR_FLOAT, data[RAKNET_SPEED_X],
                PR_FLOAT, data[RAKNET_SPEED_Y],
                PR_FLOAT, data[RAKNET_SPEED_Z],
                PR_FLOAT, data[PR_angularVelocity][0],
                PR_FLOAT, data[PR_angularVelocity][1],
                PR_FLOAT, data[PR_angularVelocity][2]
            );
        }

        stock BS_ReadPassengerSync(BitStream:bs, data[RAKNET_PASSENGER_SYNC])
        {
            BS_ReadValue(
                bs,
                PR_UINT16, data[RAKNET_VEHICLE],
                PR_BITS, data[PR_driveBy], 2,
                PR_BITS, data[PR_seatId], 6,
                PR_BITS, data[PR_additionalKey], 2,
                PR_BITS, data[PR_weaponId], 6,
                PR_UINT8, data[PR_playerHealth],
                PR_UINT8, data[PR_playerArmour],
                PR_UINT16, data[PR_lrKey],
                PR_UINT16, data[PR_udKey],
                PR_UINT16, data[PR_keys],
                PR_FLOAT, data[RAKNET_POS_X],
                PR_FLOAT, data[RAKNET_POS_Y],
                PR_FLOAT, data[RAKNET_POS_Z]
            );
        }

        stock BS_ReadUnoccupiedSync(BitStream:bs, data[PR_UnoccupiedSync])
        {
            BS_ReadValue(
                bs,
                PR_UINT16, data[RAKNET_VEHICLE],
                PR_UINT8, data[PR_seatId],
                PR_FLOAT, data[PR_roll][0],
                PR_FLOAT, data[PR_roll][1],
                PR_FLOAT, data[PR_roll][2],
                PR_FLOAT, data[PR_direction][0],
                PR_FLOAT, data[PR_direction][1],
                PR_FLOAT, data[PR_direction][2],
                PR_FLOAT, data[RAKNET_POS_X],
                PR_FLOAT, data[RAKNET_POS_Y],
                PR_FLOAT, data[RAKNET_POS_Z],
                PR_FLOAT, data[RAKNET_SPEED_X],
                PR_FLOAT, data[RAKNET_SPEED_Y],
                PR_FLOAT, data[RAKNET_SPEED_Z],
                PR_FLOAT, data[PR_angularVelocity][0],
                PR_FLOAT, data[PR_angularVelocity][1],
                PR_FLOAT, data[PR_angularVelocity][2],
                PR_FLOAT, data[PR_vehicleHealth]
            );
        }

        stock BS_ReadAimSync(BitStream:bs, data[PR_AimSync])
        {
            BS_ReadValue(
                bs,
                PR_UINT8, data[PR_camMode],
                PR_FLOAT, data[PR_camFrontVec][0],
                PR_FLOAT, data[PR_camFrontVec][1],
                PR_FLOAT, data[PR_camFrontVec][2],
                PR_FLOAT, data[PR_camPos][0],
                PR_FLOAT, data[PR_camPos][1],
                PR_FLOAT, data[PR_camPos][2],
                PR_FLOAT, data[PR_aimZ],
                PR_BITS, data[PR_weaponState], 2,
                PR_BITS, data[PR_camZoom], 6,
                PR_UINT8, data[PR_aspectRatio]
            );
        }

        stock BS_WriteOnFootSync(BitStream:bs, data[RAKNET_ONFOOT_SYNC])
        {
            BS_WriteValue(
                bs,
                PR_UINT16, data[PR_lrKey],
                PR_UINT16, data[PR_udKey],
                PR_UINT16, data[PR_keys],
                PR_FLOAT, data[RAKNET_POS_X],
                PR_FLOAT, data[RAKNET_POS_Y],
                PR_FLOAT, data[RAKNET_POS_Z],
                PR_FLOAT, data[RAKNET_QUAT_X],
                PR_FLOAT, data[RAKNET_QUAT_Y],
                PR_FLOAT, data[RAKNET_QUAT_Z],
                PR_FLOAT, data[RAKNET_QUAT_R],
                PR_UINT8, data[PR_health],
                PR_UINT8, data[PR_armour],
                PR_BITS, data[PR_additionalKey], 2,
                PR_BITS, data[RAKNET_WEAPON], 6,
                PR_UINT8, data[RAKNET_ACTION],
                PR_FLOAT, data[RAKNET_SPEED_X],
                PR_FLOAT, data[RAKNET_SPEED_Y],
                PR_FLOAT, data[RAKNET_SPEED_Z],
                PR_FLOAT, data[PR_surfingOffsets][0],
                PR_FLOAT, data[PR_surfingOffsets][1],
                PR_FLOAT, data[PR_surfingOffsets][2],
                PR_UINT16, data[PR_surfingVehicleId],
                PR_INT16, data[RAKNET_ANIM],
                PR_INT16, data[PR_animationFlags]
            );
        }

        stock BS_WriteInCarSync(BitStream:bs, data[RAKNET_DRIVER_SYNC])
        {
            BS_WriteValue(
                bs,
                PR_UINT16, data[RAKNET_VEHICLE],
                PR_UINT16, data[PR_lrKey],
                PR_UINT16, data[PR_udKey],
                PR_UINT16, data[PR_keys],
                PR_FLOAT, data[RAKNET_QUAT_X],
                PR_FLOAT, data[RAKNET_QUAT_Y],
                PR_FLOAT, data[RAKNET_QUAT_Z],
                PR_FLOAT, data[RAKNET_QUAT_R],
				
                PR_FLOAT, data[RAKNET_POS_X],
                PR_FLOAT, data[RAKNET_POS_Y],
                PR_FLOAT, data[RAKNET_POS_Z],
				
                PR_FLOAT, data[RAKNET_SPEED_X],
                PR_FLOAT, data[RAKNET_SPEED_Y],
                PR_FLOAT, data[RAKNET_SPEED_Z],
                PR_FLOAT, data[PR_vehicleHealth],
                PR_UINT8, data[PR_playerHealth],
                PR_UINT8, data[PR_armour],
                PR_BITS, data[PR_additionalKey], 2,
                PR_BITS, data[PR_weaponId], 6,
                PR_UINT8, data[PR_sirenState],
                PR_UINT8, data[PR_landingGearState],
                PR_UINT16, data[PR_trailerId],
                PR_FLOAT, data[PR_trainSpeed]
            );
        }

        stock BS_WriteTrailerSync(BitStream:bs, data[PR_TrailerSync])
        {
            BS_WriteValue(
                bs,
                PR_UINT16, data[PR_trailerId],
                PR_FLOAT, data[RAKNET_POS_X],
                PR_FLOAT, data[RAKNET_POS_Y],
                PR_FLOAT, data[RAKNET_POS_Z],
                PR_FLOAT, data[RAKNET_QUAT_X],
                PR_FLOAT, data[RAKNET_QUAT_Y],
                PR_FLOAT, data[RAKNET_QUAT_Z],
                PR_FLOAT, data[RAKNET_QUAT_R],
                PR_FLOAT, data[RAKNET_SPEED_X],
                PR_FLOAT, data[RAKNET_SPEED_Y],
                PR_FLOAT, data[RAKNET_SPEED_Z],
                PR_FLOAT, data[PR_angularVelocity][0],
                PR_FLOAT, data[PR_angularVelocity][1],
                PR_FLOAT, data[PR_angularVelocity][2]
            );
        }

        stock BS_WritePassengerSync(BitStream:bs, data[RAKNET_PASSENGER_SYNC])
        {
            BS_WriteValue(
                bs,
                PR_UINT16, data[RAKNET_VEHICLE],
                PR_BITS, data[PR_driveBy], 2,
                PR_BITS, data[PR_seatId], 6,
                PR_BITS, data[PR_additionalKey], 2,
                PR_BITS, data[PR_weaponId], 6,
                PR_UINT8, data[PR_playerHealth],
                PR_UINT8, data[PR_playerArmour],
                PR_UINT16, data[PR_lrKey],
                PR_UINT16, data[PR_udKey],
                PR_UINT16, data[PR_keys],
                PR_FLOAT, data[RAKNET_POS_X],
                PR_FLOAT, data[RAKNET_POS_Y],
                PR_FLOAT, data[RAKNET_POS_Z]
            );
        }

        stock BS_WriteUnoccupiedSync(BitStream:bs, data[PR_UnoccupiedSync])
        {
            BS_WriteValue(
                bs,
                PR_UINT16, data[RAKNET_VEHICLE],
                PR_UINT8, data[PR_seatId],
                PR_FLOAT, data[PR_roll][0],
                PR_FLOAT, data[PR_roll][1],
                PR_FLOAT, data[PR_roll][2],
                PR_FLOAT, data[PR_direction][0],
                PR_FLOAT, data[PR_direction][1],
                PR_FLOAT, data[PR_direction][2],
                PR_FLOAT, data[RAKNET_POS_X],
                PR_FLOAT, data[RAKNET_POS_Y],
                PR_FLOAT, data[RAKNET_POS_Z],
                PR_FLOAT, data[RAKNET_SPEED_X],
                PR_FLOAT, data[RAKNET_SPEED_Y],
                PR_FLOAT, data[RAKNET_SPEED_Z],
                PR_FLOAT, data[PR_angularVelocity][0],
                PR_FLOAT, data[PR_angularVelocity][1],
                PR_FLOAT, data[PR_angularVelocity][2],
                PR_FLOAT, data[PR_vehicleHealth]
            );
        }

        stock BS_WriteAimSync(BitStream:bs, data[PR_AimSync])
        {
            BS_WriteValue(
                bs,
                PR_UINT8, data[PR_camMode],
                PR_FLOAT, data[PR_camFrontVec][0],
                PR_FLOAT, data[PR_camFrontVec][1],
                PR_FLOAT, data[PR_camFrontVec][2],
                PR_FLOAT, data[PR_camPos][0],
                PR_FLOAT, data[PR_camPos][1],
                PR_FLOAT, data[PR_camPos][2],
                PR_FLOAT, data[PR_aimZ],
                PR_BITS, data[PR_weaponState], 2,
                PR_BITS, data[PR_camZoom], 6,
                PR_UINT8, data[PR_aspectRatio]
            );
        }


        native PR_RegHandler(id, const publicname[], PR_HandlerType:type);

        /*
         * playerid == -1 => send to all players (broadcast)
         */

        forward OnIncomingPacket(playerid, packetid, BitStream:bs);
        forward OnIncomingRPC(playerid, rpcid, BitStream:bs);
        forward OnOutcomingPacket(playerid, packetid, BitStream:bs);
        forward OnOutcomingRPC(playerid, rpcid, BitStream:bs);
    #endif // !defined __cplusplus
#endif // PAWNRAKNET_INC_
