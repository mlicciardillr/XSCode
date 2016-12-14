//
// File generated by rootcint at Fri Oct  4 16:39:36 2013

// Do NOT change. Changes will be lost next time file is generated
//

#include "RConfig.h" //rootcint 4834
#if !defined(R__ACCESS_IN_SYMBOL)
//Break the privacy of classes -- Disabled for the moment
#define private public
#define protected public
#endif

// Since CINT ignores the std namespace, we need to do so in this file.
namespace std {} using namespace std;
#include "Ingrid1stReducSummaryDict.h"

#include "TCollectionProxyInfo.h"
#include "TClass.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"

// START OF SHADOWS

namespace ROOT {
   namespace Shadow {
   } // of namespace Shadow
} // of namespace ROOT
// END OF SHADOWS

namespace ROOT {
   void Ingrid1stReducSummary_ShowMembers(void *obj, TMemberInspector &R__insp, char *R__parent);
   static void *new_Ingrid1stReducSummary(void *p = 0);
   static void *newArray_Ingrid1stReducSummary(Long_t size, void *p);
   static void delete_Ingrid1stReducSummary(void *p);
   static void deleteArray_Ingrid1stReducSummary(void *p);
   static void destruct_Ingrid1stReducSummary(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Ingrid1stReducSummary*)
   {
      ::Ingrid1stReducSummary *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::Ingrid1stReducSummary >(0);
      static ::ROOT::TGenericClassInfo 
         instance("Ingrid1stReducSummary", ::Ingrid1stReducSummary::Class_Version(), "Ingrid1stReducSummary.h", 16,
                  typeid(::Ingrid1stReducSummary), DefineBehavior(ptr, ptr),
                  &::Ingrid1stReducSummary::Dictionary, isa_proxy, 0,
                  sizeof(::Ingrid1stReducSummary) );
      instance.SetNew(&new_Ingrid1stReducSummary);
      instance.SetNewArray(&newArray_Ingrid1stReducSummary);
      instance.SetDelete(&delete_Ingrid1stReducSummary);
      instance.SetDeleteArray(&deleteArray_Ingrid1stReducSummary);
      instance.SetDestructor(&destruct_Ingrid1stReducSummary);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Ingrid1stReducSummary*)
   {
      return GenerateInitInstanceLocal((::Ingrid1stReducSummary*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::Ingrid1stReducSummary*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
TClass *Ingrid1stReducSummary::fgIsA = 0;  // static to hold class pointer

//______________________________________________________________________________
const char *Ingrid1stReducSummary::Class_Name()
{
   return "Ingrid1stReducSummary";
}

//______________________________________________________________________________
const char *Ingrid1stReducSummary::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Ingrid1stReducSummary*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int Ingrid1stReducSummary::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Ingrid1stReducSummary*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
void Ingrid1stReducSummary::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Ingrid1stReducSummary*)0x0)->GetClass();
}

//______________________________________________________________________________
TClass *Ingrid1stReducSummary::Class()
{
   if (!fgIsA) fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Ingrid1stReducSummary*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
void Ingrid1stReducSummary::Streamer(TBuffer &R__b)
{
   // Stream an object of class Ingrid1stReducSummary.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TObject::Streamer(R__b);
      R__b >> hitmod;
      R__b >> hitcyc;
      R__b >> xhitbit;
      R__b >> yhitbit;
      R__b >> nhitxlyr;
      R__b >> nhitylyr;
      R__b >> xtotpe;
      R__b >> ytotpe;
      R__b >> xtracklike;
      R__b >> ytracklike;
      {
         vector<int> &R__stl =  hity;
         R__stl.clear();
         int R__i, R__n;
         R__b >> R__n;
         R__stl.reserve(R__n);
         for (R__i = 0; R__i < R__n; R__i++) {
            int R__t;
            R__b >> R__t;
            R__stl.push_back(R__t);
         }
      }
      {
         vector<int> &R__stl =  hitx;
         R__stl.clear();
         int R__i, R__n;
         R__b >> R__n;
         R__stl.reserve(R__n);
         for (R__i = 0; R__i < R__n; R__i++) {
            int R__t;
            R__b >> R__t;
            R__stl.push_back(R__t);
         }
      }
      {
         vector<int> &R__stl =  hitxz;
         R__stl.clear();
         int R__i, R__n;
         R__b >> R__n;
         R__stl.reserve(R__n);
         for (R__i = 0; R__i < R__n; R__i++) {
            int R__t;
            R__b >> R__t;
            R__stl.push_back(R__t);
         }
      }
      {
         vector<int> &R__stl =  hityz;
         R__stl.clear();
         int R__i, R__n;
         R__b >> R__n;
         R__stl.reserve(R__n);
         for (R__i = 0; R__i < R__n; R__i++) {
            int R__t;
            R__b >> R__t;
            R__stl.push_back(R__t);
         }
      }
      R__b >> nhits;
      int R__i;
      for (R__i = 0; R__i < 1000; R__i++)
         fIngridHit[R__i].Streamer(R__b);
      R__b.CheckByteCount(R__s, R__c, Ingrid1stReducSummary::IsA());
   } else {
      R__c = R__b.WriteVersion(Ingrid1stReducSummary::IsA(), kTRUE);
      TObject::Streamer(R__b);
      R__b << hitmod;
      R__b << hitcyc;
      R__b << xhitbit;
      R__b << yhitbit;
      R__b << nhitxlyr;
      R__b << nhitylyr;
      R__b << xtotpe;
      R__b << ytotpe;
      R__b << xtracklike;
      R__b << ytracklike;
      {
         vector<int> &R__stl =  hity;
         int R__n=(&R__stl) ? int(R__stl.size()) : 0;
         R__b << R__n;
         if(R__n) {
            vector<int>::iterator R__k;
            for (R__k = R__stl.begin(); R__k != R__stl.end(); ++R__k) {
            R__b << (*R__k);
            }
         }
      }
      {
         vector<int> &R__stl =  hitx;
         int R__n=(&R__stl) ? int(R__stl.size()) : 0;
         R__b << R__n;
         if(R__n) {
            vector<int>::iterator R__k;
            for (R__k = R__stl.begin(); R__k != R__stl.end(); ++R__k) {
            R__b << (*R__k);
            }
         }
      }
      {
         vector<int> &R__stl =  hitxz;
         int R__n=(&R__stl) ? int(R__stl.size()) : 0;
         R__b << R__n;
         if(R__n) {
            vector<int>::iterator R__k;
            for (R__k = R__stl.begin(); R__k != R__stl.end(); ++R__k) {
            R__b << (*R__k);
            }
         }
      }
      {
         vector<int> &R__stl =  hityz;
         int R__n=(&R__stl) ? int(R__stl.size()) : 0;
         R__b << R__n;
         if(R__n) {
            vector<int>::iterator R__k;
            for (R__k = R__stl.begin(); R__k != R__stl.end(); ++R__k) {
            R__b << (*R__k);
            }
         }
      }
      R__b << nhits;
      int R__i;
      for (R__i = 0; R__i < 1000; R__i++)
         fIngridHit[R__i].Streamer(R__b);
      R__b.SetByteCount(R__c, kTRUE);
   }
}

//______________________________________________________________________________
void Ingrid1stReducSummary::ShowMembers(TMemberInspector &R__insp, char *R__parent)
{
      // Inspect the data members of an object of class Ingrid1stReducSummary.
      TClass *R__cl = ::Ingrid1stReducSummary::IsA();
      Int_t R__ncp = strlen(R__parent);
      if (R__ncp || R__cl || R__insp.IsA()) { }
      R__insp.Inspect(R__cl, R__parent, "hitmod", &hitmod);
      R__insp.Inspect(R__cl, R__parent, "hitcyc", &hitcyc);
      R__insp.Inspect(R__cl, R__parent, "xhitbit", &xhitbit);
      R__insp.Inspect(R__cl, R__parent, "yhitbit", &yhitbit);
      R__insp.Inspect(R__cl, R__parent, "nhitxlyr", &nhitxlyr);
      R__insp.Inspect(R__cl, R__parent, "nhitylyr", &nhitylyr);
      R__insp.Inspect(R__cl, R__parent, "xtotpe", &xtotpe);
      R__insp.Inspect(R__cl, R__parent, "ytotpe", &ytotpe);
      R__insp.Inspect(R__cl, R__parent, "xtracklike", &xtracklike);
      R__insp.Inspect(R__cl, R__parent, "ytracklike", &ytracklike);
      R__insp.Inspect(R__cl, R__parent, "hity", (void*)&hity);
      ::ROOT::GenericShowMembers("vector<int>", (void*)&hity, R__insp, strcat(R__parent,"hity."),false);
      R__parent[R__ncp] = 0;
      R__insp.Inspect(R__cl, R__parent, "hitx", (void*)&hitx);
      ::ROOT::GenericShowMembers("vector<int>", (void*)&hitx, R__insp, strcat(R__parent,"hitx."),false);
      R__parent[R__ncp] = 0;
      R__insp.Inspect(R__cl, R__parent, "hitxz", (void*)&hitxz);
      ::ROOT::GenericShowMembers("vector<int>", (void*)&hitxz, R__insp, strcat(R__parent,"hitxz."),false);
      R__parent[R__ncp] = 0;
      R__insp.Inspect(R__cl, R__parent, "hityz", (void*)&hityz);
      ::ROOT::GenericShowMembers("vector<int>", (void*)&hityz, R__insp, strcat(R__parent,"hityz."),false);
      R__parent[R__ncp] = 0;
      R__insp.Inspect(R__cl, R__parent, "nhits", &nhits);
      R__insp.Inspect(R__cl, R__parent, "fIngridHit[1000]", fIngridHit);
      TObject::ShowMembers(R__insp, R__parent);
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_Ingrid1stReducSummary(void *p) {
      return  p ? new(p) ::Ingrid1stReducSummary : new ::Ingrid1stReducSummary;
   }
   static void *newArray_Ingrid1stReducSummary(Long_t nElements, void *p) {
      return p ? new(p) ::Ingrid1stReducSummary[nElements] : new ::Ingrid1stReducSummary[nElements];
   }
   // Wrapper around operator delete
   static void delete_Ingrid1stReducSummary(void *p) {
      delete ((::Ingrid1stReducSummary*)p);
   }
   static void deleteArray_Ingrid1stReducSummary(void *p) {
      delete [] ((::Ingrid1stReducSummary*)p);
   }
   static void destruct_Ingrid1stReducSummary(void *p) {
      typedef ::Ingrid1stReducSummary current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::Ingrid1stReducSummary

namespace ROOT {
   void vectorlEintgR_ShowMembers(void *obj, TMemberInspector &R__insp, char *R__parent);
   static void vectorlEintgR_Dictionary();
   static void *new_vectorlEintgR(void *p = 0);
   static void *newArray_vectorlEintgR(Long_t size, void *p);
   static void delete_vectorlEintgR(void *p);
   static void deleteArray_vectorlEintgR(void *p);
   static void destruct_vectorlEintgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<int>*)
   {
      vector<int> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<int>),0);
      static ::ROOT::TGenericClassInfo 
         instance("vector<int>", -2, "prec_stl/vector", 49,
                  typeid(vector<int>), DefineBehavior(ptr, ptr),
                  0, &vectorlEintgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<int>) );
      instance.SetNew(&new_vectorlEintgR);
      instance.SetNewArray(&newArray_vectorlEintgR);
      instance.SetDelete(&delete_vectorlEintgR);
      instance.SetDeleteArray(&deleteArray_vectorlEintgR);
      instance.SetDestructor(&destruct_vectorlEintgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<int> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<int>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static void vectorlEintgR_Dictionary() {
      ::ROOT::GenerateInitInstanceLocal((const vector<int>*)0x0)->GetClass();
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEintgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<int> : new vector<int>;
   }
   static void *newArray_vectorlEintgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<int>[nElements] : new vector<int>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEintgR(void *p) {
      delete ((vector<int>*)p);
   }
   static void deleteArray_vectorlEintgR(void *p) {
      delete [] ((vector<int>*)p);
   }
   static void destruct_vectorlEintgR(void *p) {
      typedef vector<int> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<int>

/********************************************************
* Ingrid1stReducSummaryDict.cc
* CAUTION: DON'T CHANGE THIS FILE. THIS FILE IS AUTOMATICALLY GENERATED
*          FROM HEADER FILES LISTED IN G__setup_cpp_environmentXXX().
*          CHANGE THOSE HEADER FILES AND REGENERATE THIS FILE.
********************************************************/

#ifdef G__MEMTEST
#undef malloc
#undef free
#endif

#if defined(__GNUC__) && (__GNUC__ > 3) && (__GNUC_MINOR__ > 1)
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif

extern "C" void G__cpp_reset_tagtableIngrid1stReducSummaryDict();

extern "C" void G__set_cpp_environmentIngrid1stReducSummaryDict() {
  G__add_compiledheader("TObject.h");
  G__add_compiledheader("TMemberInspector.h");
  G__add_compiledheader("Ingrid1stReducSummary.h");
  G__cpp_reset_tagtableIngrid1stReducSummaryDict();
}
#include <new>
extern "C" int G__cpp_dllrevIngrid1stReducSummaryDict() { return(30051515); }

/*********************************************************
* Member function Interface Method
*********************************************************/

/* Ingrid1stReducSummary */
static int G__Ingrid1stReducSummaryDict_171_0_1(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
   Ingrid1stReducSummary* p = NULL;
   char* gvp = (char*) G__getgvp();
   int n = G__getaryconstruct();
   if (n) {
     if ((gvp == (char*)G__PVOID) || (gvp == 0)) {
       p = new Ingrid1stReducSummary[n];
     } else {
       p = new((void*) gvp) Ingrid1stReducSummary[n];
     }
   } else {
     if ((gvp == (char*)G__PVOID) || (gvp == 0)) {
       p = new Ingrid1stReducSummary;
     } else {
       p = new((void*) gvp) Ingrid1stReducSummary;
     }
   }
   result7->obj.i = (long) p;
   result7->ref = (long) p;
   result7->type = 'u';
   result7->tagnum = G__get_linked_tagnum(&G__Ingrid1stReducSummaryDictLN_Ingrid1stReducSummary);
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__Ingrid1stReducSummaryDict_171_0_2(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
   Ingrid1stReducSummary* p = NULL;
   char* gvp = (char*) G__getgvp();
   //m: 1
   if ((gvp == (char*)G__PVOID) || (gvp == 0)) {
     p = new Ingrid1stReducSummary(*(Ingrid1stReducSummary*) libp->para[0].ref);
   } else {
     p = new((void*) gvp) Ingrid1stReducSummary(*(Ingrid1stReducSummary*) libp->para[0].ref);
   }
   result7->obj.i = (long) p;
   result7->ref = (long) p;
   result7->type = 'u';
   result7->tagnum = G__get_linked_tagnum(&G__Ingrid1stReducSummaryDictLN_Ingrid1stReducSummary);
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__Ingrid1stReducSummaryDict_171_0_4(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      ((Ingrid1stReducSummary*) G__getstructoffset())->Print();
      G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__Ingrid1stReducSummaryDict_171_0_5(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      ((Ingrid1stReducSummary*) G__getstructoffset())->AddIngridHit((IngridHitSummary*) G__int(libp->para[0]));
      G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__Ingrid1stReducSummaryDict_171_0_6(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 85, (long) ((const Ingrid1stReducSummary*) G__getstructoffset())->GetIngridHit((int) G__int(libp->para[0])));
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__Ingrid1stReducSummaryDict_171_0_7(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 85, (long) Ingrid1stReducSummary::Class());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__Ingrid1stReducSummaryDict_171_0_8(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 67, (long) Ingrid1stReducSummary::Class_Name());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__Ingrid1stReducSummaryDict_171_0_9(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 115, (long) Ingrid1stReducSummary::Class_Version());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__Ingrid1stReducSummaryDict_171_0_10(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      Ingrid1stReducSummary::Dictionary();
      G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__Ingrid1stReducSummaryDict_171_0_14(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      ((Ingrid1stReducSummary*) G__getstructoffset())->StreamerNVirtual(*(TBuffer*) libp->para[0].ref);
      G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__Ingrid1stReducSummaryDict_171_0_15(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 67, (long) Ingrid1stReducSummary::DeclFileName());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__Ingrid1stReducSummaryDict_171_0_16(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 105, (long) Ingrid1stReducSummary::ImplFileLine());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__Ingrid1stReducSummaryDict_171_0_17(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 67, (long) Ingrid1stReducSummary::ImplFileName());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__Ingrid1stReducSummaryDict_171_0_18(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 105, (long) Ingrid1stReducSummary::DeclFileLine());
   return(1 || funcname || hash || result7 || libp) ;
}

// automatic destructor
typedef Ingrid1stReducSummary G__TIngrid1stReducSummary;
static int G__Ingrid1stReducSummaryDict_171_0_19(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
   char* gvp = (char*) G__getgvp();
   long soff = G__getstructoffset();
   int n = G__getaryconstruct();
   //
   //has_a_delete: 1
   //has_own_delete1arg: 0
   //has_own_delete2arg: 0
   //
   if (!soff) {
     return(1);
   }
   if (n) {
     if (gvp == (char*)G__PVOID) {
       delete[] (Ingrid1stReducSummary*) soff;
     } else {
       G__setgvp((long) G__PVOID);
       for (int i = n - 1; i >= 0; --i) {
         ((Ingrid1stReducSummary*) (soff+(sizeof(Ingrid1stReducSummary)*i)))->~G__TIngrid1stReducSummary();
       }
       G__setgvp((long)gvp);
     }
   } else {
     if (gvp == (char*)G__PVOID) {
       delete (Ingrid1stReducSummary*) soff;
     } else {
       G__setgvp((long) G__PVOID);
       ((Ingrid1stReducSummary*) (soff))->~G__TIngrid1stReducSummary();
       G__setgvp((long)gvp);
     }
   }
   G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

// automatic assignment operator
static int G__Ingrid1stReducSummaryDict_171_0_20(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
   Ingrid1stReducSummary* dest = (Ingrid1stReducSummary*) G__getstructoffset();
   *dest = *(Ingrid1stReducSummary*) libp->para[0].ref;
   const Ingrid1stReducSummary& obj = *dest;
   result7->ref = (long) (&obj);
   result7->obj.i = (long) (&obj);
   return(1 || funcname || hash || result7 || libp) ;
}


/* Setting up global function */

/*********************************************************
* Member function Stub
*********************************************************/

/* Ingrid1stReducSummary */

/*********************************************************
* Global function Stub
*********************************************************/

/*********************************************************
* Get size of pointer to member function
*********************************************************/
class G__Sizep2memfuncIngrid1stReducSummaryDict {
 public:
  G__Sizep2memfuncIngrid1stReducSummaryDict(): p(&G__Sizep2memfuncIngrid1stReducSummaryDict::sizep2memfunc) {}
    size_t sizep2memfunc() { return(sizeof(p)); }
  private:
    size_t (G__Sizep2memfuncIngrid1stReducSummaryDict::*p)();
};

size_t G__get_sizep2memfuncIngrid1stReducSummaryDict()
{
  G__Sizep2memfuncIngrid1stReducSummaryDict a;
  G__setsizep2memfunc((int)a.sizep2memfunc());
  return((size_t)a.sizep2memfunc());
}


/*********************************************************
* virtual base class offset calculation interface
*********************************************************/

   /* Setting up class inheritance */

/*********************************************************
* Inheritance information setup/
*********************************************************/
extern "C" void G__cpp_setup_inheritanceIngrid1stReducSummaryDict() {

   /* Setting up class inheritance */
   if(0==G__getnumbaseclass(G__get_linked_tagnum(&G__Ingrid1stReducSummaryDictLN_Ingrid1stReducSummary))) {
     Ingrid1stReducSummary *G__Lderived;
     G__Lderived=(Ingrid1stReducSummary*)0x1000;
     {
       TObject *G__Lpbase=(TObject*)G__Lderived;
       G__inheritance_setup(G__get_linked_tagnum(&G__Ingrid1stReducSummaryDictLN_Ingrid1stReducSummary),G__get_linked_tagnum(&G__Ingrid1stReducSummaryDictLN_TObject),(long)G__Lpbase-(long)G__Lderived,1,1);
     }
   }
}

/*********************************************************
* typedef information setup/
*********************************************************/
extern "C" void G__cpp_setup_typetableIngrid1stReducSummaryDict() {

   /* Setting up typedef entry */
   G__search_typename2("Version_t",115,-1,0,-1);
   G__setnewtype(-1,"Class version identifier (short)",0);
   G__search_typename2("iterator<std::bidirectional_iterator_tag,TObject*,std::ptrdiff_t,const TObject**,const TObject*&>",117,G__get_linked_tagnum(&G__Ingrid1stReducSummaryDictLN_iteratorlEbidirectional_iterator_tagcOTObjectmUcOlongcOconstsPTObjectmUmUcOconstsPTObjectmUaNgR),0,-1);
   G__setnewtype(-1,NULL,0);
   G__search_typename2("iterator<bidirectional_iterator_tag,TObject*>",117,G__get_linked_tagnum(&G__Ingrid1stReducSummaryDictLN_iteratorlEbidirectional_iterator_tagcOTObjectmUcOlongcOconstsPTObjectmUmUcOconstsPTObjectmUaNgR),0,-1);
   G__setnewtype(-1,NULL,0);
   G__search_typename2("iterator<bidirectional_iterator_tag,TObject*,long>",117,G__get_linked_tagnum(&G__Ingrid1stReducSummaryDictLN_iteratorlEbidirectional_iterator_tagcOTObjectmUcOlongcOconstsPTObjectmUmUcOconstsPTObjectmUaNgR),0,-1);
   G__setnewtype(-1,NULL,0);
   G__search_typename2("iterator<bidirectional_iterator_tag,TObject*,long,const TObject**>",117,G__get_linked_tagnum(&G__Ingrid1stReducSummaryDictLN_iteratorlEbidirectional_iterator_tagcOTObjectmUcOlongcOconstsPTObjectmUmUcOconstsPTObjectmUaNgR),0,-1);
   G__setnewtype(-1,NULL,0);
   G__search_typename2("vector<int>",117,G__get_linked_tagnum(&G__Ingrid1stReducSummaryDictLN_vectorlEintcOallocatorlEintgRsPgR),0,-1);
   G__setnewtype(-1,NULL,0);
   G__search_typename2("reverse_iterator<const_iterator>",117,G__get_linked_tagnum(&G__Ingrid1stReducSummaryDictLN_reverse_iteratorlEvectorlEintcOallocatorlEintgRsPgRcLcLiteratorgR),0,G__get_linked_tagnum(&G__Ingrid1stReducSummaryDictLN_vectorlEintcOallocatorlEintgRsPgR));
   G__setnewtype(-1,NULL,0);
   G__search_typename2("reverse_iterator<iterator>",117,G__get_linked_tagnum(&G__Ingrid1stReducSummaryDictLN_reverse_iteratorlEvectorlEintcOallocatorlEintgRsPgRcLcLiteratorgR),0,G__get_linked_tagnum(&G__Ingrid1stReducSummaryDictLN_vectorlEintcOallocatorlEintgRsPgR));
   G__setnewtype(-1,NULL,0);
}

/*********************************************************
* Data Member information setup/
*********************************************************/

   /* Setting up class,struct,union tag member variable */

   /* Ingrid1stReducSummary */
static void G__setup_memvarIngrid1stReducSummary(void) {
   G__tag_memvar_setup(G__get_linked_tagnum(&G__Ingrid1stReducSummaryDictLN_Ingrid1stReducSummary));
   { Ingrid1stReducSummary *p; p=(Ingrid1stReducSummary*)0x1000; if (p) { }
   G__memvar_setup((void*)((long)(&p->hitmod)-(long)(p)),105,0,0,-1,-1,-1,1,"hitmod=",0,"### hit module");
   G__memvar_setup((void*)((long)(&p->hitcyc)-(long)(p)),105,0,0,-1,-1,-1,1,"hitcyc=",0,"### hit cycle");
   G__memvar_setup((void*)((long)(&p->xhitbit)-(long)(p)),104,0,0,-1,-1,-1,1,"xhitbit=",0,"### hit X layer 11(TPL) bits");
   G__memvar_setup((void*)((long)(&p->yhitbit)-(long)(p)),104,0,0,-1,-1,-1,1,"yhitbit=",0,"### hit Y layer 11(TPL) bits");
   G__memvar_setup((void*)((long)(&p->nhitxlyr)-(long)(p)),105,0,0,-1,-1,-1,1,"nhitxlyr=",0,"### number of hit X layers");
   G__memvar_setup((void*)((long)(&p->nhitylyr)-(long)(p)),105,0,0,-1,-1,-1,1,"nhitylyr=",0,"### number of hit Y layers");
   G__memvar_setup((void*)((long)(&p->xtotpe)-(long)(p)),102,0,0,-1,-1,-1,1,"xtotpe=",0,"### total p.e. in X layers");
   G__memvar_setup((void*)((long)(&p->ytotpe)-(long)(p)),102,0,0,-1,-1,-1,1,"ytotpe=",0,"### total p.e. in Y layers");
   G__memvar_setup((void*)((long)(&p->xtracklike)-(long)(p)),103,0,0,-1,-1,-1,1,"xtracklike=",0,"### definition of track-like will be changed or removed");
   G__memvar_setup((void*)((long)(&p->ytracklike)-(long)(p)),103,0,0,-1,-1,-1,1,"ytracklike=",0,"### now(2010/2/12), 3 layers hit in a row ");
   G__memvar_setup((void*)((long)(&p->hity)-(long)(p)),117,0,0,G__get_linked_tagnum(&G__Ingrid1stReducSummaryDictLN_vectorlEintcOallocatorlEintgRsPgR),G__defined_typename("vector<int>"),-1,1,"hity=",0,"### temporary for stdudying external(?) redioactivity");
   G__memvar_setup((void*)((long)(&p->hitx)-(long)(p)),117,0,0,G__get_linked_tagnum(&G__Ingrid1stReducSummaryDictLN_vectorlEintcOallocatorlEintgRsPgR),G__defined_typename("vector<int>"),-1,1,"hitx=",0,(char*)NULL);
   G__memvar_setup((void*)((long)(&p->hitxz)-(long)(p)),117,0,0,G__get_linked_tagnum(&G__Ingrid1stReducSummaryDictLN_vectorlEintcOallocatorlEintgRsPgR),G__defined_typename("vector<int>"),-1,1,"hitxz=",0,(char*)NULL);
   G__memvar_setup((void*)((long)(&p->hityz)-(long)(p)),117,0,0,G__get_linked_tagnum(&G__Ingrid1stReducSummaryDictLN_vectorlEintcOallocatorlEintgRsPgR),G__defined_typename("vector<int>"),-1,1,"hityz=",0,(char*)NULL);
   G__memvar_setup((void*)((long)(&p->nhits)-(long)(p)),105,0,0,-1,-1,-1,1,"nhits=",0,(char*)NULL);
   G__memvar_setup((void*)0,117,0,0,G__get_linked_tagnum(&G__Ingrid1stReducSummaryDictLN_TRef),-1,-1,4,"fIngridHit[1000]=",0,(char*)NULL);
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__Ingrid1stReducSummaryDictLN_TClass),-1,-2,4,"fgIsA=",0,(char*)NULL);
   }
   G__tag_memvar_reset();
}

extern "C" void G__cpp_setup_memvarIngrid1stReducSummaryDict() {
}
/***********************************************************
************************************************************
************************************************************
************************************************************
************************************************************
************************************************************
************************************************************
***********************************************************/

/*********************************************************
* Member function information setup for each class
*********************************************************/
static void G__setup_memfuncIngrid1stReducSummary(void) {
   /* Ingrid1stReducSummary */
   G__tag_memfunc_setup(G__get_linked_tagnum(&G__Ingrid1stReducSummaryDictLN_Ingrid1stReducSummary));
   G__memfunc_setup("Ingrid1stReducSummary",2134,G__Ingrid1stReducSummaryDict_171_0_1, 105, G__get_linked_tagnum(&G__Ingrid1stReducSummaryDictLN_Ingrid1stReducSummary), -1, 0, 0, 1, 1, 0, "", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("Ingrid1stReducSummary",2134,G__Ingrid1stReducSummaryDict_171_0_2, 105, G__get_linked_tagnum(&G__Ingrid1stReducSummaryDictLN_Ingrid1stReducSummary), -1, 0, 1, 1, 1, 0, "u 'Ingrid1stReducSummary' - 11 - basicsum", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("Clear",487,(G__InterfaceMethod) NULL,121, -1, -1, 0, 1, 1, 1, 0, "C - 'Option_t' 10 '\"\"' option", (char*)NULL, (void*) NULL, 1);
   G__memfunc_setup("Print",525,G__Ingrid1stReducSummaryDict_171_0_4, 121, -1, -1, 0, 0, 1, 1, 0, "", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("AddIngridHit",1163,G__Ingrid1stReducSummaryDict_171_0_5, 121, -1, -1, 0, 1, 1, 1, 0, "U 'IngridHitSummary' - 0 - hit", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("GetIngridHit",1186,G__Ingrid1stReducSummaryDict_171_0_6, 85, G__get_linked_tagnum(&G__Ingrid1stReducSummaryDictLN_IngridHitSummary), -1, 0, 1, 1, 1, 8, "i - - 0 - i", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("Class",502,G__Ingrid1stReducSummaryDict_171_0_7, 85, G__get_linked_tagnum(&G__Ingrid1stReducSummaryDictLN_TClass), -1, 0, 0, 3, 1, 0, "", (char*)NULL, (void*) (TClass* (*)())(&Ingrid1stReducSummary::Class), 0);
   G__memfunc_setup("Class_Name",982,G__Ingrid1stReducSummaryDict_171_0_8, 67, -1, -1, 0, 0, 3, 1, 1, "", (char*)NULL, (void*) (const char* (*)())(&Ingrid1stReducSummary::Class_Name), 0);
   G__memfunc_setup("Class_Version",1339,G__Ingrid1stReducSummaryDict_171_0_9, 115, -1, G__defined_typename("Version_t"), 0, 0, 3, 1, 0, "", (char*)NULL, (void*) (Version_t (*)())(&Ingrid1stReducSummary::Class_Version), 0);
   G__memfunc_setup("Dictionary",1046,G__Ingrid1stReducSummaryDict_171_0_10, 121, -1, -1, 0, 0, 3, 1, 0, "", (char*)NULL, (void*) (void (*)())(&Ingrid1stReducSummary::Dictionary), 0);
   G__memfunc_setup("IsA",253,(G__InterfaceMethod) NULL,85, G__get_linked_tagnum(&G__Ingrid1stReducSummaryDictLN_TClass), -1, 0, 0, 1, 1, 8, "", (char*)NULL, (void*) NULL, 1);
   G__memfunc_setup("ShowMembers",1132,(G__InterfaceMethod) NULL,121, -1, -1, 0, 2, 1, 1, 0, 
"u 'TMemberInspector' - 1 - insp C - - 0 - parent", (char*)NULL, (void*) NULL, 1);
   G__memfunc_setup("Streamer",835,(G__InterfaceMethod) NULL,121, -1, -1, 0, 1, 1, 1, 0, "u 'TBuffer' - 1 - b", (char*)NULL, (void*) NULL, 1);
   G__memfunc_setup("StreamerNVirtual",1656,G__Ingrid1stReducSummaryDict_171_0_14, 121, -1, -1, 0, 1, 1, 1, 0, "u 'TBuffer' - 1 - b", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("DeclFileName",1145,G__Ingrid1stReducSummaryDict_171_0_15, 67, -1, -1, 0, 0, 3, 1, 1, "", (char*)NULL, (void*) (const char* (*)())(&Ingrid1stReducSummary::DeclFileName), 0);
   G__memfunc_setup("ImplFileLine",1178,G__Ingrid1stReducSummaryDict_171_0_16, 105, -1, -1, 0, 0, 3, 1, 0, "", (char*)NULL, (void*) (int (*)())(&Ingrid1stReducSummary::ImplFileLine), 0);
   G__memfunc_setup("ImplFileName",1171,G__Ingrid1stReducSummaryDict_171_0_17, 67, -1, -1, 0, 0, 3, 1, 1, "", (char*)NULL, (void*) (const char* (*)())(&Ingrid1stReducSummary::ImplFileName), 0);
   G__memfunc_setup("DeclFileLine",1152,G__Ingrid1stReducSummaryDict_171_0_18, 105, -1, -1, 0, 0, 3, 1, 0, "", (char*)NULL, (void*) (int (*)())(&Ingrid1stReducSummary::DeclFileLine), 0);
   // automatic destructor
   G__memfunc_setup("~Ingrid1stReducSummary", 2260, G__Ingrid1stReducSummaryDict_171_0_19, (int) ('y'), -1, -1, 0, 0, 1, 1, 0, "", (char*) NULL, (void*) NULL, 1);
   // automatic assignment operator
   G__memfunc_setup("operator=", 937, G__Ingrid1stReducSummaryDict_171_0_20, (int) ('u'), G__get_linked_tagnum(&G__Ingrid1stReducSummaryDictLN_Ingrid1stReducSummary), -1, 1, 1, 1, 1, 0, "u 'Ingrid1stReducSummary' - 11 - -", (char*) NULL, (void*) NULL, 0);
   G__tag_memfunc_reset();
}


/*********************************************************
* Member function information setup
*********************************************************/
extern "C" void G__cpp_setup_memfuncIngrid1stReducSummaryDict() {
}

/*********************************************************
* Global variable information setup for each class
*********************************************************/
static void G__cpp_setup_global0() {

   /* Setting up global variables */
   G__resetplocal();

}

static void G__cpp_setup_global1() {

   G__resetglobalenv();
}
extern "C" void G__cpp_setup_globalIngrid1stReducSummaryDict() {
  G__cpp_setup_global0();
  G__cpp_setup_global1();
}

/*********************************************************
* Global function information setup for each class
*********************************************************/
static void G__cpp_setup_func0() {
   G__lastifuncposition();

}

static void G__cpp_setup_func1() {
}

static void G__cpp_setup_func2() {
}

static void G__cpp_setup_func3() {
}

static void G__cpp_setup_func4() {
}

static void G__cpp_setup_func5() {
}

static void G__cpp_setup_func6() {
}

static void G__cpp_setup_func7() {
}

static void G__cpp_setup_func8() {
}

static void G__cpp_setup_func9() {
}

static void G__cpp_setup_func10() {
}

static void G__cpp_setup_func11() {

   G__resetifuncposition();
}

extern "C" void G__cpp_setup_funcIngrid1stReducSummaryDict() {
  G__cpp_setup_func0();
  G__cpp_setup_func1();
  G__cpp_setup_func2();
  G__cpp_setup_func3();
  G__cpp_setup_func4();
  G__cpp_setup_func5();
  G__cpp_setup_func6();
  G__cpp_setup_func7();
  G__cpp_setup_func8();
  G__cpp_setup_func9();
  G__cpp_setup_func10();
  G__cpp_setup_func11();
}

/*********************************************************
* Class,struct,union,enum tag information setup
*********************************************************/
/* Setup class/struct taginfo */
G__linked_taginfo G__Ingrid1stReducSummaryDictLN_TClass = { "TClass" , 99 , -1 };
G__linked_taginfo G__Ingrid1stReducSummaryDictLN_TBuffer = { "TBuffer" , 99 , -1 };
G__linked_taginfo G__Ingrid1stReducSummaryDictLN_TMemberInspector = { "TMemberInspector" , 99 , -1 };
G__linked_taginfo G__Ingrid1stReducSummaryDictLN_TObject = { "TObject" , 99 , -1 };
G__linked_taginfo G__Ingrid1stReducSummaryDictLN_iteratorlEbidirectional_iterator_tagcOTObjectmUcOlongcOconstsPTObjectmUmUcOconstsPTObjectmUaNgR = { "iterator<bidirectional_iterator_tag,TObject*,long,const TObject**,const TObject*&>" , 115 , -1 };
G__linked_taginfo G__Ingrid1stReducSummaryDictLN_TRef = { "TRef" , 99 , -1 };
G__linked_taginfo G__Ingrid1stReducSummaryDictLN_IngridHitSummary = { "IngridHitSummary" , 99 , -1 };
G__linked_taginfo G__Ingrid1stReducSummaryDictLN_Ingrid1stReducSummary = { "Ingrid1stReducSummary" , 99 , -1 };
G__linked_taginfo G__Ingrid1stReducSummaryDictLN_vectorlEintcOallocatorlEintgRsPgR = { "vector<int,allocator<int> >" , 99 , -1 };
G__linked_taginfo G__Ingrid1stReducSummaryDictLN_reverse_iteratorlEvectorlEintcOallocatorlEintgRsPgRcLcLiteratorgR = { "reverse_iterator<vector<int,allocator<int> >::iterator>" , 99 , -1 };

/* Reset class/struct taginfo */
extern "C" void G__cpp_reset_tagtableIngrid1stReducSummaryDict() {
  G__Ingrid1stReducSummaryDictLN_TClass.tagnum = -1 ;
  G__Ingrid1stReducSummaryDictLN_TBuffer.tagnum = -1 ;
  G__Ingrid1stReducSummaryDictLN_TMemberInspector.tagnum = -1 ;
  G__Ingrid1stReducSummaryDictLN_TObject.tagnum = -1 ;
  G__Ingrid1stReducSummaryDictLN_iteratorlEbidirectional_iterator_tagcOTObjectmUcOlongcOconstsPTObjectmUmUcOconstsPTObjectmUaNgR.tagnum = -1 ;
  G__Ingrid1stReducSummaryDictLN_TRef.tagnum = -1 ;
  G__Ingrid1stReducSummaryDictLN_IngridHitSummary.tagnum = -1 ;
  G__Ingrid1stReducSummaryDictLN_Ingrid1stReducSummary.tagnum = -1 ;
  G__Ingrid1stReducSummaryDictLN_vectorlEintcOallocatorlEintgRsPgR.tagnum = -1 ;
  G__Ingrid1stReducSummaryDictLN_reverse_iteratorlEvectorlEintcOallocatorlEintgRsPgRcLcLiteratorgR.tagnum = -1 ;
}


extern "C" void G__cpp_setup_tagtableIngrid1stReducSummaryDict() {

   /* Setting up class,struct,union tag entry */
   G__get_linked_tagnum_fwd(&G__Ingrid1stReducSummaryDictLN_TClass);
   G__get_linked_tagnum_fwd(&G__Ingrid1stReducSummaryDictLN_TBuffer);
   G__get_linked_tagnum_fwd(&G__Ingrid1stReducSummaryDictLN_TMemberInspector);
   G__get_linked_tagnum_fwd(&G__Ingrid1stReducSummaryDictLN_TObject);
   G__get_linked_tagnum_fwd(&G__Ingrid1stReducSummaryDictLN_iteratorlEbidirectional_iterator_tagcOTObjectmUcOlongcOconstsPTObjectmUmUcOconstsPTObjectmUaNgR);
   G__get_linked_tagnum_fwd(&G__Ingrid1stReducSummaryDictLN_TRef);
   G__get_linked_tagnum_fwd(&G__Ingrid1stReducSummaryDictLN_IngridHitSummary);
   G__tagtable_setup(G__get_linked_tagnum(&G__Ingrid1stReducSummaryDictLN_Ingrid1stReducSummary),sizeof(Ingrid1stReducSummary),-1,30464,(char*)NULL,G__setup_memvarIngrid1stReducSummary,G__setup_memfuncIngrid1stReducSummary);
   G__get_linked_tagnum_fwd(&G__Ingrid1stReducSummaryDictLN_vectorlEintcOallocatorlEintgRsPgR);
   G__get_linked_tagnum_fwd(&G__Ingrid1stReducSummaryDictLN_reverse_iteratorlEvectorlEintcOallocatorlEintgRsPgRcLcLiteratorgR);
}
extern "C" void G__cpp_setupIngrid1stReducSummaryDict(void) {
  G__check_setup_version(30051515,"G__cpp_setupIngrid1stReducSummaryDict()");
  G__set_cpp_environmentIngrid1stReducSummaryDict();
  G__cpp_setup_tagtableIngrid1stReducSummaryDict();

  G__cpp_setup_inheritanceIngrid1stReducSummaryDict();

  G__cpp_setup_typetableIngrid1stReducSummaryDict();

  G__cpp_setup_memvarIngrid1stReducSummaryDict();

  G__cpp_setup_memfuncIngrid1stReducSummaryDict();
  G__cpp_setup_globalIngrid1stReducSummaryDict();
  G__cpp_setup_funcIngrid1stReducSummaryDict();

   if(0==G__getsizep2memfunc()) G__get_sizep2memfuncIngrid1stReducSummaryDict();
  return;
}
class G__cpp_setup_initIngrid1stReducSummaryDict {
  public:
    G__cpp_setup_initIngrid1stReducSummaryDict() { G__add_setup_func("Ingrid1stReducSummaryDict",(G__incsetup)(&G__cpp_setupIngrid1stReducSummaryDict)); G__call_setup_funcs(); }
   ~G__cpp_setup_initIngrid1stReducSummaryDict() { G__remove_setup_func("Ingrid1stReducSummaryDict"); }
};
G__cpp_setup_initIngrid1stReducSummaryDict G__cpp_setup_initializerIngrid1stReducSummaryDict;

