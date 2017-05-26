/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#pragma once

#include "thrift/compiler/test/fixtures/basic/gen-cpp2/MyServicePrioParent.h"
#include <thrift/lib/cpp/TApplicationException.h>
#include <folly/io/IOBuf.h>
#include <folly/io/IOBufQueue.h>
#include <thrift/lib/cpp/transport/THeader.h>
#include <thrift/lib/cpp2/server/Cpp2ConnContext.h>
#include <thrift/lib/cpp2/GeneratedCodeHelper.h>
#include <thrift/lib/cpp2/GeneratedSerializationCodeHelper.h>

namespace cpp2 {

typedef apache::thrift::ThriftPresult<false> MyServicePrioParent_ping_pargs;
typedef apache::thrift::ThriftPresult<true> MyServicePrioParent_ping_presult;
typedef apache::thrift::ThriftPresult<false> MyServicePrioParent_pong_pargs;
typedef apache::thrift::ThriftPresult<true> MyServicePrioParent_pong_presult;
template <typename ProtocolIn_, typename ProtocolOut_>
void MyServicePrioParentAsyncProcessor::_processInThread_ping(std::unique_ptr<apache::thrift::ResponseChannel::Request> req, std::unique_ptr<folly::IOBuf> buf, std::unique_ptr<ProtocolIn_> iprot, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) {
  auto pri = iface_->getRequestPriority(ctx, apache::thrift::concurrency::IMPORTANT);
  processInThread<ProtocolIn_, ProtocolOut_>(std::move(req), std::move(buf),std::move(iprot), ctx, eb, tm, pri, false, &MyServicePrioParentAsyncProcessor::process_ping<ProtocolIn_, ProtocolOut_>, this);
}

template <typename ProtocolIn_, typename ProtocolOut_>
void MyServicePrioParentAsyncProcessor::process_ping(std::unique_ptr<apache::thrift::ResponseChannel::Request> req, std::unique_ptr<folly::IOBuf> buf, std::unique_ptr<ProtocolIn_> iprot,apache::thrift::Cpp2RequestContext* ctx,folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) {
  // make sure getConnectionContext is null
  // so async calls don't accidentally use it
  iface_->setConnectionContext(nullptr);
  MyServicePrioParent_ping_pargs args;
  std::unique_ptr<apache::thrift::ContextStack> c(this->getContextStack(this->getServiceName(), "MyServicePrioParent.ping", ctx));
  try {
    deserializeRequest(args, buf.get(), iprot.get(), c.get());
  }
  catch (const std::exception& ex) {
    ProtocolOut_ prot;
    if (req) {
      LOG(ERROR) << ex.what() << " in function ping";
      apache::thrift::TApplicationException x(apache::thrift::TApplicationException::TApplicationExceptionType::PROTOCOL_ERROR, ex.what());
      folly::IOBufQueue queue = serializeException("ping", &prot, ctx->getProtoSeqId(), nullptr, x);
      queue.append(apache::thrift::transport::THeader::transform(queue.move(), ctx->getHeader()->getWriteTransforms(), ctx->getHeader()->getMinCompressBytes()));
      eb->runInEventBaseThread([queue = std::move(queue), req = std::move(req)]() mutable {
        req->sendReply(queue.move());
      }
      );
      return;
    }
    else {
      LOG(ERROR) << ex.what() << " in oneway function ping";
    }
  }
  auto callback = std::make_unique<apache::thrift::HandlerCallback<void>>(std::move(req), std::move(c), return_ping<ProtocolIn_,ProtocolOut_>, throw_ping<ProtocolIn_, ProtocolOut_>, throw_wrapped_ping<ProtocolIn_, ProtocolOut_>, ctx->getProtoSeqId(), eb, tm, ctx);
  if (!callback->isRequestActive()) {
    callback.release()->deleteInThread();
    return;
  }
  ctx->setStartedProcessing();
  iface_->async_tm_ping(std::move(callback));
}

template <class ProtocolIn_, class ProtocolOut_>
folly::IOBufQueue MyServicePrioParentAsyncProcessor::return_ping(int32_t protoSeqId, apache::thrift::ContextStack* ctx) {
  ProtocolOut_ prot;
  MyServicePrioParent_ping_presult result;
  return serializeResponse("ping", &prot, protoSeqId, ctx, result);
}

template <class ProtocolIn_, class ProtocolOut_>
void MyServicePrioParentAsyncProcessor::throw_ping(std::unique_ptr<apache::thrift::ResponseChannel::Request> req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,std::exception_ptr ep,apache::thrift::Cpp2RequestContext* reqCtx) {
  ProtocolOut_ prot;
  try {
    std::rethrow_exception(ep);
  }
  catch (const std::exception& e) {
    auto ew = folly::exception_wrapper(ep, e);
    if (req) {
      LOG(ERROR) << folly::exceptionStr(e).toStdString() << " in function ping";
      apache::thrift::TApplicationException x(folly::exceptionStr(e).toStdString());
      ctx->userExceptionWrapped(false, ew);
      ctx->handlerErrorWrapped(ew);
      folly::IOBufQueue queue = serializeException("ping", &prot, protoSeqId, ctx, x);
      queue.append(apache::thrift::transport::THeader::transform(queue.move(), reqCtx->getHeader()->getWriteTransforms(), reqCtx->getHeader()->getMinCompressBytes()));
      req->sendReply(queue.move());
      return;
    }
    else {
      LOG(ERROR) << folly::exceptionStr(e).toStdString() << " in oneway function ping";
    }
  }
  catch (...) {
    if (req) {
      LOG(ERROR) << "<unknown exception>" << " in function ping";
      apache::thrift::TApplicationException x("<unknown exception>");
      folly::IOBufQueue queue = serializeException("ping", &prot, protoSeqId, nullptr, x);
      queue.append(apache::thrift::transport::THeader::transform(queue.move(), reqCtx->getHeader()->getWriteTransforms(), reqCtx->getHeader()->getMinCompressBytes()));
      req->sendReply(queue.move());
      return;
    }
    else {
      LOG(ERROR) << "<unknown exception>" << " in oneway function ping";
    }
  }
}

template <class ProtocolIn_, class ProtocolOut_>
void MyServicePrioParentAsyncProcessor::throw_wrapped_ping(std::unique_ptr<apache::thrift::ResponseChannel::Request> req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx) {
  if (!ew) {
    return;
  }
  ProtocolOut_ prot;
   {
    if (req) {
      LOG(ERROR) << ew.what().toStdString() << " in function ping";
      apache::thrift::TApplicationException x(ew.what().toStdString());
      ctx->userExceptionWrapped(false, ew);
      ctx->handlerErrorWrapped(ew);
      folly::IOBufQueue queue = serializeException("ping", &prot, protoSeqId, ctx, x);
      queue.append(apache::thrift::transport::THeader::transform(queue.move(), reqCtx->getHeader()->getWriteTransforms(), reqCtx->getHeader()->getMinCompressBytes()));
      req->sendReply(queue.move());
      return;
    }
    else {
      LOG(ERROR) << ew.what().toStdString() << " in oneway function ping";
    }
  }
}

template <typename ProtocolIn_, typename ProtocolOut_>
void MyServicePrioParentAsyncProcessor::_processInThread_pong(std::unique_ptr<apache::thrift::ResponseChannel::Request> req, std::unique_ptr<folly::IOBuf> buf, std::unique_ptr<ProtocolIn_> iprot, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) {
  auto pri = iface_->getRequestPriority(ctx, apache::thrift::concurrency::HIGH_IMPORTANT);
  processInThread<ProtocolIn_, ProtocolOut_>(std::move(req), std::move(buf),std::move(iprot), ctx, eb, tm, pri, false, &MyServicePrioParentAsyncProcessor::process_pong<ProtocolIn_, ProtocolOut_>, this);
}

template <typename ProtocolIn_, typename ProtocolOut_>
void MyServicePrioParentAsyncProcessor::process_pong(std::unique_ptr<apache::thrift::ResponseChannel::Request> req, std::unique_ptr<folly::IOBuf> buf, std::unique_ptr<ProtocolIn_> iprot,apache::thrift::Cpp2RequestContext* ctx,folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) {
  // make sure getConnectionContext is null
  // so async calls don't accidentally use it
  iface_->setConnectionContext(nullptr);
  MyServicePrioParent_pong_pargs args;
  std::unique_ptr<apache::thrift::ContextStack> c(this->getContextStack(this->getServiceName(), "MyServicePrioParent.pong", ctx));
  try {
    deserializeRequest(args, buf.get(), iprot.get(), c.get());
  }
  catch (const std::exception& ex) {
    ProtocolOut_ prot;
    if (req) {
      LOG(ERROR) << ex.what() << " in function pong";
      apache::thrift::TApplicationException x(apache::thrift::TApplicationException::TApplicationExceptionType::PROTOCOL_ERROR, ex.what());
      folly::IOBufQueue queue = serializeException("pong", &prot, ctx->getProtoSeqId(), nullptr, x);
      queue.append(apache::thrift::transport::THeader::transform(queue.move(), ctx->getHeader()->getWriteTransforms(), ctx->getHeader()->getMinCompressBytes()));
      eb->runInEventBaseThread([queue = std::move(queue), req = std::move(req)]() mutable {
        req->sendReply(queue.move());
      }
      );
      return;
    }
    else {
      LOG(ERROR) << ex.what() << " in oneway function pong";
    }
  }
  auto callback = std::make_unique<apache::thrift::HandlerCallback<void>>(std::move(req), std::move(c), return_pong<ProtocolIn_,ProtocolOut_>, throw_pong<ProtocolIn_, ProtocolOut_>, throw_wrapped_pong<ProtocolIn_, ProtocolOut_>, ctx->getProtoSeqId(), eb, tm, ctx);
  if (!callback->isRequestActive()) {
    callback.release()->deleteInThread();
    return;
  }
  ctx->setStartedProcessing();
  iface_->async_tm_pong(std::move(callback));
}

template <class ProtocolIn_, class ProtocolOut_>
folly::IOBufQueue MyServicePrioParentAsyncProcessor::return_pong(int32_t protoSeqId, apache::thrift::ContextStack* ctx) {
  ProtocolOut_ prot;
  MyServicePrioParent_pong_presult result;
  return serializeResponse("pong", &prot, protoSeqId, ctx, result);
}

template <class ProtocolIn_, class ProtocolOut_>
void MyServicePrioParentAsyncProcessor::throw_pong(std::unique_ptr<apache::thrift::ResponseChannel::Request> req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,std::exception_ptr ep,apache::thrift::Cpp2RequestContext* reqCtx) {
  ProtocolOut_ prot;
  try {
    std::rethrow_exception(ep);
  }
  catch (const std::exception& e) {
    auto ew = folly::exception_wrapper(ep, e);
    if (req) {
      LOG(ERROR) << folly::exceptionStr(e).toStdString() << " in function pong";
      apache::thrift::TApplicationException x(folly::exceptionStr(e).toStdString());
      ctx->userExceptionWrapped(false, ew);
      ctx->handlerErrorWrapped(ew);
      folly::IOBufQueue queue = serializeException("pong", &prot, protoSeqId, ctx, x);
      queue.append(apache::thrift::transport::THeader::transform(queue.move(), reqCtx->getHeader()->getWriteTransforms(), reqCtx->getHeader()->getMinCompressBytes()));
      req->sendReply(queue.move());
      return;
    }
    else {
      LOG(ERROR) << folly::exceptionStr(e).toStdString() << " in oneway function pong";
    }
  }
  catch (...) {
    if (req) {
      LOG(ERROR) << "<unknown exception>" << " in function pong";
      apache::thrift::TApplicationException x("<unknown exception>");
      folly::IOBufQueue queue = serializeException("pong", &prot, protoSeqId, nullptr, x);
      queue.append(apache::thrift::transport::THeader::transform(queue.move(), reqCtx->getHeader()->getWriteTransforms(), reqCtx->getHeader()->getMinCompressBytes()));
      req->sendReply(queue.move());
      return;
    }
    else {
      LOG(ERROR) << "<unknown exception>" << " in oneway function pong";
    }
  }
}

template <class ProtocolIn_, class ProtocolOut_>
void MyServicePrioParentAsyncProcessor::throw_wrapped_pong(std::unique_ptr<apache::thrift::ResponseChannel::Request> req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx) {
  if (!ew) {
    return;
  }
  ProtocolOut_ prot;
   {
    if (req) {
      LOG(ERROR) << ew.what().toStdString() << " in function pong";
      apache::thrift::TApplicationException x(ew.what().toStdString());
      ctx->userExceptionWrapped(false, ew);
      ctx->handlerErrorWrapped(ew);
      folly::IOBufQueue queue = serializeException("pong", &prot, protoSeqId, ctx, x);
      queue.append(apache::thrift::transport::THeader::transform(queue.move(), reqCtx->getHeader()->getWriteTransforms(), reqCtx->getHeader()->getMinCompressBytes()));
      req->sendReply(queue.move());
      return;
    }
    else {
      LOG(ERROR) << ew.what().toStdString() << " in oneway function pong";
    }
  }
}

template <typename Protocol_>
void MyServicePrioParentAsyncClient::pingT(Protocol_* prot, bool useSync, apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback) {
  auto header = std::make_shared<apache::thrift::transport::THeader>(apache::thrift::transport::THeader::ALLOW_BIG_FRAMES);
  header->setProtocolId(getChannel()->getProtocolId());
  header->setHeaders(rpcOptions.releaseWriteHeaders());
  connectionContext_->setRequestHeader(header.get());
  std::unique_ptr<apache::thrift::ContextStack> ctx = this->getContextStack(this->getServiceName(), "MyServicePrioParent.ping", connectionContext_.get());
  MyServicePrioParent_ping_pargs args;
  auto sizer = [&](Protocol_* p) { return args.serializedSizeZC(p); };
  auto writer = [&](Protocol_* p) { args.write(p); };
  apache::thrift::clientSendT<Protocol_>(prot, rpcOptions, std::move(callback), std::move(ctx), header, channel_.get(), "ping", writer, sizer, false, useSync);
  connectionContext_->setRequestHeader(nullptr);
}

template <typename Protocol_>
folly::exception_wrapper MyServicePrioParentAsyncClient::recv_wrapped_pingT(Protocol_* prot, ::apache::thrift::ClientReceiveState& state) {
  if (state.isException()) {
    return state.exceptionWrapper();
  }
  prot->setInput(state.buf());
  auto guard = folly::makeGuard([&] {prot->setInput(nullptr);});
  apache::thrift::ContextStack* ctx = state.ctx();
  std::string fname;
  int32_t protoSeqId = 0;
  apache::thrift::MessageType mtype;
  ctx->preRead();
  folly::exception_wrapper interior_ew;
  auto caught_ew = folly::try_and_catch<std::exception, apache::thrift::TException, apache::thrift::protocol::TProtocolException>([&]() {
    prot->readMessageBegin(fname, mtype, protoSeqId);
    if (mtype == apache::thrift::T_EXCEPTION) {
      apache::thrift::TApplicationException x;
      x.read(prot);
      prot->readMessageEnd();
      interior_ew = folly::make_exception_wrapper<apache::thrift::TApplicationException>(x);
      return; // from try_and_catch
    }
    if (mtype != apache::thrift::T_REPLY) {
      prot->skip(apache::thrift::protocol::T_STRUCT);
      prot->readMessageEnd();
      interior_ew = folly::make_exception_wrapper<apache::thrift::TApplicationException>(apache::thrift::TApplicationException::TApplicationExceptionType::INVALID_MESSAGE_TYPE);
      return; // from try_and_catch
    }
    if (fname.compare("ping") != 0) {
      prot->skip(apache::thrift::protocol::T_STRUCT);
      prot->readMessageEnd();
      interior_ew = folly::make_exception_wrapper<apache::thrift::TApplicationException>(apache::thrift::TApplicationException::TApplicationExceptionType::WRONG_METHOD_NAME);
      return; // from try_and_catch
    }
    ::apache::thrift::SerializedMessage smsg;
    smsg.protocolType = prot->protocolType();
    smsg.buffer = state.buf();
    ctx->onReadData(smsg);
    MyServicePrioParent_ping_presult result;
    result.read(prot);
    prot->readMessageEnd();
    ctx->postRead(state.header(), state.buf()->length());
  }
  );
  auto ew = interior_ew ? std::move(interior_ew) : std::move(caught_ew);
  if (ew) {
    ctx->handlerErrorWrapped(ew);
  }
  return ew;
}

template <typename Protocol_>
void MyServicePrioParentAsyncClient::recv_pingT(Protocol_* prot, ::apache::thrift::ClientReceiveState& state) {
  auto ew = recv_wrapped_pingT(prot, state);
  if (ew) {
    ew.throw_exception();
  }
}

template <typename Protocol_>
void MyServicePrioParentAsyncClient::pongT(Protocol_* prot, bool useSync, apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback) {
  auto header = std::make_shared<apache::thrift::transport::THeader>(apache::thrift::transport::THeader::ALLOW_BIG_FRAMES);
  header->setProtocolId(getChannel()->getProtocolId());
  header->setHeaders(rpcOptions.releaseWriteHeaders());
  connectionContext_->setRequestHeader(header.get());
  std::unique_ptr<apache::thrift::ContextStack> ctx = this->getContextStack(this->getServiceName(), "MyServicePrioParent.pong", connectionContext_.get());
  MyServicePrioParent_pong_pargs args;
  auto sizer = [&](Protocol_* p) { return args.serializedSizeZC(p); };
  auto writer = [&](Protocol_* p) { args.write(p); };
  apache::thrift::clientSendT<Protocol_>(prot, rpcOptions, std::move(callback), std::move(ctx), header, channel_.get(), "pong", writer, sizer, false, useSync);
  connectionContext_->setRequestHeader(nullptr);
}

template <typename Protocol_>
folly::exception_wrapper MyServicePrioParentAsyncClient::recv_wrapped_pongT(Protocol_* prot, ::apache::thrift::ClientReceiveState& state) {
  if (state.isException()) {
    return state.exceptionWrapper();
  }
  prot->setInput(state.buf());
  auto guard = folly::makeGuard([&] {prot->setInput(nullptr);});
  apache::thrift::ContextStack* ctx = state.ctx();
  std::string fname;
  int32_t protoSeqId = 0;
  apache::thrift::MessageType mtype;
  ctx->preRead();
  folly::exception_wrapper interior_ew;
  auto caught_ew = folly::try_and_catch<std::exception, apache::thrift::TException, apache::thrift::protocol::TProtocolException>([&]() {
    prot->readMessageBegin(fname, mtype, protoSeqId);
    if (mtype == apache::thrift::T_EXCEPTION) {
      apache::thrift::TApplicationException x;
      x.read(prot);
      prot->readMessageEnd();
      interior_ew = folly::make_exception_wrapper<apache::thrift::TApplicationException>(x);
      return; // from try_and_catch
    }
    if (mtype != apache::thrift::T_REPLY) {
      prot->skip(apache::thrift::protocol::T_STRUCT);
      prot->readMessageEnd();
      interior_ew = folly::make_exception_wrapper<apache::thrift::TApplicationException>(apache::thrift::TApplicationException::TApplicationExceptionType::INVALID_MESSAGE_TYPE);
      return; // from try_and_catch
    }
    if (fname.compare("pong") != 0) {
      prot->skip(apache::thrift::protocol::T_STRUCT);
      prot->readMessageEnd();
      interior_ew = folly::make_exception_wrapper<apache::thrift::TApplicationException>(apache::thrift::TApplicationException::TApplicationExceptionType::WRONG_METHOD_NAME);
      return; // from try_and_catch
    }
    ::apache::thrift::SerializedMessage smsg;
    smsg.protocolType = prot->protocolType();
    smsg.buffer = state.buf();
    ctx->onReadData(smsg);
    MyServicePrioParent_pong_presult result;
    result.read(prot);
    prot->readMessageEnd();
    ctx->postRead(state.header(), state.buf()->length());
  }
  );
  auto ew = interior_ew ? std::move(interior_ew) : std::move(caught_ew);
  if (ew) {
    ctx->handlerErrorWrapped(ew);
  }
  return ew;
}

template <typename Protocol_>
void MyServicePrioParentAsyncClient::recv_pongT(Protocol_* prot, ::apache::thrift::ClientReceiveState& state) {
  auto ew = recv_wrapped_pongT(prot, state);
  if (ew) {
    ew.throw_exception();
  }
}

} // cpp2
namespace apache { namespace thrift {

}} // apache::thrift
