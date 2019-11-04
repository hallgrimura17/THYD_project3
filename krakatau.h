
#ifndef TURBOPASCAL_KRAKATAU_H
#define TURBOPASCAL_KRAKATAU_H

#include <iostream>
#include <string>
#include "bc.h"

class KrakatauAsm {
 public:

  class Instr {
   public:

    Instr( const std::string& macro_instr ) : macro_instr_(macro_instr), bc_instr_(BC::InstrCode::nop) {}

    Instr( const BC::Instr& bc_instr ) : macro_instr_(""), bc_instr_(bc_instr) {}

    Instr( const BC::Label& label ) : macro_instr_(""), bc_instr_(BC::InstrCode::nop), label_(label) {}

    std::string to_string() const {
      if ( !macro_instr_.empty() ) {
        return macro_instr_;
      }
      else if ( label_.get_num() >= 0 ) {
        return label_.to_string() + ":";
      }
      else {
        return bc_instr_.to_string();
      }
    }
   private:
    std::string macro_instr_;
    BC::Instr bc_instr_;
    BC::Label label_;
  };

  Instr macro_class( const std::string& name ) {
    set_class( name );
    return std::string(".class public super " + name );
  }

  Instr macro_class_end() {
    return std::string(".end class" );
  }

  Instr macro_code( int stack_no, int locals_no ) {
    return std::string( ".code stack "  + std::to_string(stack_no) + " locals " + std::to_string(locals_no) );

  }

  Instr macro_code_end(  ) {
    return std::string(".end code" );
  }

  Instr macro_field( const std::string& name, const std::string& signature  ) {
    return std::string(".field static "  + name + " " + signature );
  }

  Instr macro_source( const std::string& name ) {
    return std::string(".sourcefile '"  + name + "'" );
  }

  Instr macro_super(const std::string& name ) {
    return std::string(".super "  + name );
  }

  Instr macro_method( const std::string& quantifiers, const std::string& name, const std::string& signature ) {
    return std::string(".method " + quantifiers + " " + name + " : " + signature );
  }

  Instr macro_method_end( ) {
    locals_table_.clear();
    return std::string(".end method");
  }

  Instr macro_version ( int no ) {
    return std::string(".version " + std::to_string(no) + " 0");
  }

  Instr label( BC::Label label ) {
    return label;
  }

  Instr bc_iload( const std::string& name ) {
    const std::list<std::string> args{ std::to_string( get_local( name ) ) };
    return BC::Instr( BC::InstrCode::iload, args );
  }

  Instr bc_fload( const std::string& name ) {
    const std::list<std::string> args{ std::to_string( get_local( name ) ) };
    return BC::Instr( BC::InstrCode::fload, args );
  }

  Instr bc_aload( const std::string& name ) {
    const std::list<std::string> args{ std::to_string( get_local( name ) ) };
    return BC::Instr( BC::InstrCode::aload, args );
  }

  Instr bc_iaload( ) {
    return BC::Instr( BC::InstrCode::iaload );
  }

  Instr bc_faload( ) {
    return BC::Instr( BC::InstrCode::faload );
  }

  Instr bc_baload( ) {
    return BC::Instr( BC::InstrCode::baload );
  }

  Instr bc_load_sdt( LNG::SimpleDataType sdt, const std::string& name ) {
    switch ( sdt ) {
      case LNG::SimpleDataType::tBoolean:
      case LNG::SimpleDataType::tInteger:
        return bc_iload(name);
        break;
      default:
        return bc_fload(name);
    }
  }

  Instr bc_aload_sdt( LNG::SimpleDataType sdt ) {
    switch ( sdt ) {
      case LNG::SimpleDataType::tBoolean:
        return bc_baload();
        break;
      case LNG::SimpleDataType::tInteger:
        return bc_iaload();
        break;
      default:
        return bc_faload();
    }
  }

  Instr bc_istore( const std::string& name ) {
    const std::list<std::string> args{ std::to_string( get_local( name ) ) };
    return BC::Instr( BC::InstrCode::istore, args );
  }

  Instr bc_fstore( const std::string& name ) {
    const std::list<std::string> args{ std::to_string( get_local( name ) ) };
    return BC::Instr( BC::InstrCode::fstore, args );
  }

  Instr bc_astore( const std::string& name ) {
    const std::list<std::string> args{ std::to_string( get_local( name ) ) };
    return BC::Instr( BC::InstrCode::astore, args );
  }

  Instr bc_iastore(  ) {
    return BC::Instr( BC::InstrCode::iastore );
  }

  Instr bc_fastore( ) {
    return BC::Instr( BC::InstrCode::fastore );
  }

  Instr bc_bastore(  ) {
    return BC::Instr( BC::InstrCode::bastore );
  }

  Instr bc_store_sdt( LNG::SimpleDataType sdt, const std::string& name ) {
    switch ( sdt ) {
      case LNG::SimpleDataType::tBoolean:
      case LNG::SimpleDataType::tInteger:
        return bc_istore(name);
        break;
      default:
        return bc_fstore(name);
    }
  }

  Instr bc_astore_sdt( LNG::SimpleDataType sdt ) {
    switch ( sdt ) {
      case LNG::SimpleDataType::tBoolean:
        return bc_bastore();
        break;
      case LNG::SimpleDataType::tInteger:
        return bc_iastore();
        break;
      default:
        return bc_fastore();
    }
  }

  Instr bc_getstatic( const std::string class_name, const std::string& name, std::string signature = "" ) {
    std::list<std::string> args { "Field", class_name, name, signature };
    return BC::Instr( BC::InstrCode::getstatic, args );
  }

  Instr bc_putstatic( const std::string class_name, const std::string& name, std::string signature = "" ) {
    std::list<std::string> args { "Field", class_name, name, signature };
    return BC::Instr( BC::InstrCode::putstatic, args );
  }

  Instr bc_return( LNG::SimpleDataType sdt = LNG::SimpleDataType::tVoid ) {
    switch ( sdt ) {
      case LNG::SimpleDataType::tBoolean:
      case LNG::SimpleDataType::tInteger:
        return BC::Instr(BC::InstrCode::ireturn );
      case LNG::SimpleDataType::tReal:
        return BC::Instr(BC::InstrCode::freturn );
      case LNG::SimpleDataType::tVoid:
        return BC::Instr(BC::InstrCode::_return );
    }
  }

  Instr bc_invokespecial( const std::string& name, const std::string& signature ) {
    std::list<std::string> args { "Method", "java/lang/Object", name, signature };
    return BC::Instr( BC::InstrCode::invokespecial, args );
  }

  Instr bc_invokestatic( const std::string& name, const std::string& signature ) {
    std::list<std::string> args {"Method", get_class(), name, signature };
    return BC::Instr( BC::InstrCode::invokestatic, args );
  }

  Instr bc_invokevirtual( const std::string& name, const std::string& cls, const std::string& signature ) {
    std::list<std::string> args {"Method", cls, name, signature };
    return BC::Instr( BC::InstrCode::invokevirtual, args );
  }

  Instr bc_ldc( int value ) {
    std::list<std::string> args { std::to_string(value) };
    return BC::Instr( BC::InstrCode::ldc, args );
  }

  Instr bc_ldc( float value ) {
    std::list<std::string> args { std::to_string(value)+"f" };
    return BC::Instr( BC::InstrCode::ldc, args );
  }

  Instr bc_ldc( bool value ) {
    std::list<std::string> args { std::to_string(value) };
    return BC::Instr( BC::InstrCode::ldc, args );
  }

  Instr bc_ldc( const std::string& value ) {
    std::list<std::string> args { value };
    return BC::Instr( BC::InstrCode::ldc, args );
  }

  Instr bc_ifeq( const BC::Label& label ) {
    std::list<std::string> args { label.to_string() };
    return BC::Instr( BC::InstrCode::ifeq, args );
  }

  Instr bc_ifne( const BC::Label& label ) {
    std::list<std::string> args { label.to_string() };
    return BC::Instr( BC::InstrCode::ifne, args );
  }

  Instr bc_if( LNG::ExprOperator op, const BC::Label& label ) {
    std::list<std::string> args { label.to_string() };
    switch ( op ) {
      case LNG::ExprOperator::o_eq:   return BC::Instr( BC::InstrCode::ifeq, args );
      case LNG::ExprOperator::o_neq:  return BC::Instr( BC::InstrCode::ifne, args );
      case LNG::ExprOperator::o_gt:   return BC::Instr( BC::InstrCode::ifgt, args );
      case LNG::ExprOperator::o_gteq: return BC::Instr( BC::InstrCode::ifge, args );
      case LNG::ExprOperator::o_lt:   return BC::Instr( BC::InstrCode::iflt, args );
      case LNG::ExprOperator::o_lteq: return BC::Instr( BC::InstrCode::ifle, args );
      default:
        assert(false); // Must call with a relational operator.
    }
  }
  Instr bc_fcmpl(  ) {
    return BC::Instr( BC::InstrCode::fcmpl );
  }

  Instr bc_if_icmp( LNG::ExprOperator op, const BC::Label& label ) {
    std::list<std::string> args { label.to_string() };
    switch ( op ) {
      case LNG::ExprOperator::o_eq:   return BC::Instr( BC::InstrCode::if_icmpeq, args );
      case LNG::ExprOperator::o_neq:  return BC::Instr( BC::InstrCode::if_icmpne, args );
      case LNG::ExprOperator::o_gt:   return BC::Instr( BC::InstrCode::if_icmpgt, args );
      case LNG::ExprOperator::o_gteq: return BC::Instr( BC::InstrCode::if_icmpge, args );
      case LNG::ExprOperator::o_lt:   return BC::Instr( BC::InstrCode::if_icmplt, args );
      case LNG::ExprOperator::o_lteq: return BC::Instr( BC::InstrCode::if_icmple, args );
      default:
        assert(false); // Must call with a relational operator.
    }
  }

  Instr bc_goto( const BC::Label& label ) {
    std::list<std::string> args { label.to_string() };
    return BC::Instr( BC::InstrCode::_goto, args );
  }

  Instr bc_newarray( LNG::SimpleDataType sdt ) {
    static std::map<LNG::SimpleDataType, std::string> tostr = {
        { LNG::SimpleDataType::tVoid, "void" },
        { LNG::SimpleDataType::tInteger, "int" },
        { LNG::SimpleDataType::tReal, "float" },
        { LNG::SimpleDataType::tBoolean, "boolean" },
    };
    std::list<std::string> args { tostr[sdt] };
    return BC::Instr( BC::InstrCode::newarray, args );
  }

  Instr bc_i2f(  ) {
    return BC::Instr( BC::InstrCode::i2f );
  }

  BC::Label label_new() {
    return BC::Label( ++label_number_ );
  }

  void label_reset() {
    label_number_ = 0;
  }

  void set_class( const std::string method ) {
    method_ = method;
  }

  std::string get_class( ) const {
    return method_;
  }

  void add_to_locals( const std::string& name ) {
    locals_table_[name] = locals_table_.size();
  }

  int get_local( const std::string& name ) {
    auto it = locals_table_.find( name );
    if ( it != locals_table_.end() ) {
      return it->second;
    }
    return 0;
  }

 private:

  int label_number_ = 0;
  std::string method_;
  std::map<std::string,int> locals_table_;
};

#endif //TURBOPASCAL_KRAKATAU_H
