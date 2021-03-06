#pragma once
#include "src/rpc/amqp/AmqpRpcConnection.h"
#include "src/rpc/amqp/AmqpRpcConnAcceptor.h"
#include "src/rpc/p2p/P2pRpcConnection.h"
#include "src/rpc/p2p/P2pRpcConnAcceptor.h"
#include "src/rpc/RpcInvokerFacatory.h"


namespace brpc{

RpcInvoker* RpcInvokerFacatory::loadRpcInvoker(String url, RpcService* dispatcher,
	AuthChecker* authChecker, cstring serializerType, unsigned int timeout)
{
	if (url.startWith("amqp://"))
	{
		return new AmqpRpcConnection(url, dispatcher, authChecker,
			serializerType, timeout);
	}
	else
	{
		return new P2pRpcConnection(url, dispatcher, authChecker,
			serializerType, timeout);
	}
}

RpcConnAcceptor* RpcInvokerFacatory::loadRpcAcceptor(String url, RpcServer* server)
{
	if (url.startWith("amqp://"))
	{
		return new AmqpRpcConnAcceptor(server);
	}
	else
	{
		return new P2pRpcConnAcceptor(server);
	}
}

}//end of namespace brpc