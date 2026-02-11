package(default_visibility = ["//visibility:public"])

cc_library(
    name = "fake_response_publisher_lib",
    srcs = ["fake_response_publisher.cpp"],
    deps = [
        "//orchagent:mock_response_publisher_lib",
        "//orchagent:orchagent_lib",
        "//lib:lib_utils",
        "@com_google_googletest//:gtest",
        "@com_google_googletest//:gtest_main",
    ],
)

COMMON_COPTS = [
    "-Wno-sign-compare",
    "-fno-stack-protector",
] + select({
    "//:debug_mode": ["-ggdb -DDEBUG"],
    "//conditions:default": ["-g -DNDEBUG"],
})

COMMON_LINKOPTS = []

ALL_TEST_HDRS = glob(["*.h"])

cc_library(
    name = "common_test_lib",
    srcs = [
        "common/mock_shell_command.cpp",
        "fake_netlink.cpp",
        "fake_warmstarthelper.cpp",
        "mock_dbconnector.cpp",
        "mock_hiredis.cpp",
        "mock_orchagent_main.cpp",
        "mock_redisreply.cpp",
        "mock_table.cpp",
    ],
    hdrs = ALL_TEST_HDRS + [],
    copts = COMMON_COPTS,
    defines = [
        "DRAIN_MMU_WHEN_APPLYING_BUFFER_CONFIG",
    ],
    linkopts = COMMON_LINKOPTS,
    deps = [
        "//cfgmgr:cfgmgr_base_lib",
        "//cfgmgr:shellcmd",
        "//lib:lib_utils",
        "//orchagent:orchagent_lib",
        "//orchagent:orchagent_test_lib",
        "//warmrestart:warmrestarthelper_lib",
        "@com_google_googletest//:gtest",
        "@com_google_googletest//:gtest_main",
        "//bazel/hiredis:hiredis",
        "//bazel/libnl3:libnl-genl-3",
        "//bazel/libnl3:libnl-route-3",
        "//bazel/libnl3:libnl3",
        "//bazel/saivs:saivs",
        "//bazel/swsscommon:swsscommon",
        "//bazel/zmq:zmq",
    ],
)

cc_library(
    name = "tests_deps_wrapper",
    deps = [
          ":fake_response_publisher_lib",
          "//cfgmgr:cfgmgr_base_lib",
          "//lib:lib_utils",
          "//orchagent:orchagent_test_lib",
          "//warmrestart:warmrestartassist_lib",
          "@com_google_googletest//:gtest",
          "@com_google_googletest//:gtest_main",
          "//bazel/hiredis:hiredis",
          "//bazel/libnl3:libnl-genl-3",
          "//bazel/libnl3:libnl-route-3",
          "//bazel/libnl3:libnl3",
          "//bazel/saimetadata:saimeta",
          "//bazel/saimetadata:saimetadata",
          "//bazel/saivs:saivs",
          "//bazel/zmq:zmq",
    ],
    linkopts = COMMON_LINKOPTS,
)

# TODO BL: This target is known to be broken, we're working on a fix
cc_test(
    name = "tests",
    srcs = [
        "aclorch_ut.cpp",
        "portsorch_ut.cpp",
        "routeorch_ut.cpp",
        "qosorch_ut.cpp",
        "bufferorch_ut.cpp",
        "buffermgrdyn_ut.cpp",
        "fdborch/flush_syncd_notif_ut.cpp",
        "copp_ut.cpp",
        "copporch_ut.cpp",
        "saispy_ut.cpp",
        "consumer_ut.cpp",
        "sfloworh_ut.cpp",
        "ut_saihelper.cpp",
        "mock_orchagent_main.cpp",
        "mock_dbconnector.cpp",
        "mock_consumerstatetable.cpp",
        "mock_subscriberstatetable.cpp",
        "common/mock_shell_command.cpp",
        "mock_table.cpp",
        "mock_hiredis.cpp",
        "mock_redisreply.cpp",
        "mock_sai_api.cpp",
        "bulker_ut.cpp",
        "portmgr_ut.cpp",
        "sflowmgrd_ut.cpp",
        "swssnet_ut.cpp",
        "switchorch_ut.cpp",
        "warmrestarthelper_ut.cpp",
        "neighorch_ut.cpp",
        "twamporch_ut.cpp",
        "flexcounter_ut.cpp",
        "flowcounterrouteorch_ut.cpp",
        "orchdaemon_ut.cpp",
        "intfsorch_ut.cpp",
        "mux_rollback_ut.cpp",
        "warmrestartassist_ut.cpp",
        "test_failure_handling.cpp",
    ] + ALL_TEST_HDRS,
    copts = COMMON_COPTS,
    linkopts = COMMON_LINKOPTS + [
      # Ref: https://linux.die.net/man/1/ld
      # "-Wl,--exclude-libs=libcommon.a",
      # TODO BL: Let's pray that this works
      "-Wl,--remap-inputs=/usr/lib/x86_64-linux-gnu/libbsd.so.*=/dev/null",
      # "-Wl,--remap-inputs=/usr/lib/x86_64-linux-gnu/libbsd.so.0.11.7=/dev/null",
      # "-Wl,--remap-inputs=/usr/lib/x86_64-linux-gnu/libbsd.so.0.11.7=/usr/lib/x86_64-linux-gnu/libbsd.so.0.12.1",
      # "-Wl,--remap-inputs=/usr/lib/x86_64-linux-gnu/libbsd.so.0.11.7=/home/blorente/code/github.com/sonic-net/sonic-swss/libbsd.so.0.11.7",
      "-lboost_serialization",
      # TODO BL: obviously absolute paths are bad.
      # TODO BL: These are also bad, and they may even work
      "-Lbazel-out/k8-fastbuild/bin/external/rules_distroless++apt+bookworm_libboost-serialization1.74-dev-amd64_1.74.0-ds1-21/usr/lib/x86_64-linux-gnu/",
      "-Wl,-rpath-link=bazel-out/k8-fastbuild/bin/external/rules_distroless++apt+bookworm_libboost-serialization1.74-dev-amd64_1.74.0-ds1-21/usr/lib/x86_64-linux-gnu",

      # TODO BL: This can't be the right way to do this,
      # but it's picking up libnl-nf-3 from the import which is just `.so`, and not the 
      # actual _so_libs, which is .so.200
      "-Wl,-rpath=$ORIGIN/../../_solib_k8/_U_A_Arules_Udistroless++apt+bookworm_Ulibnl-nf-3-200-amd64_U3.7.0-0.2-b1_S_S_C_Uso_Ulibs___Uexternal_Srules_Udistroless++apt+bookworm_Ulibnl-nf-3-200-amd64_U3.7.0-0.2-b1_Susr_Slib_Sx86_U64-linux-gnu/",
      # "-Wl,-rpath=$ORIGIN/../../_solib_k8/_U_A_Arules_Udistroless++apt+bookworm_Ulibhiredis0.14-amd64_U0.14.1-3_S_S_C_Uso_Ulibs___Uexternal_Srules_Udistroless++apt+bookworm_Ulibhiredis0.14-amd64_U0.14.1-3_Susr_Slib_Sx86_U64-linux-gnu",
      # "-Wl,-rpath=$ORIGIN/../../_solib_k8/_U_A_Arules_Udistroless++apt+bookworm_Ulibyang2-amd64_U2.1.30-2_S_S_C_Uso_Ulibs___Uexternal_Srules_Udistroless++apt+bookworm_Ulibyang2-amd64_U2.1.30-2_Susr_Slib_Sx86_U64-linux-gnu",
      # "-Wl,-rpath=$ORIGIN/../../_solib_k8/_U_A_Arules_Udistroless++apt+bookworm_Ulibzmq5-amd64_U4.3.4-6_S_S_C_Uso_Ulibs___Uexternal_Srules_Udistroless++apt+bookworm_Ulibzmq5-amd64_U4.3.4-6_Susr_Slib_Sx86_U64-linux-gnu",    
      # "-Wl,-rpath=$ORIGIN/../../_solib_k8/_U_A_Arules_Udistroless++apt+bookworm_Ulibzmq5-amd64_U4.3.4-6_S_S_C_Uso_Ulibs___Uexternal_Srules_Udistroless++apt+bookworm_Ulibzmq5-amd64_U4.3.4-6_Susr_Slib_Sx86_U64-linux-gnu",    
      # "-Wl,-rpath=$ORIGIN/../../_solib_k8/_U_A_Arules_Udistroless++apt+bookworm_Ulibnorm1-amd64_U1.5.9-dfsg-2_S_S_C_Uso_Ulibs___Uexternal_Srules_Udistroless++apt+bookworm_Ulibnorm1-amd64_U1.5.9-dfsg-2_Susr_Slib_Sx86_U64-linux-gnu",
    ],
    dynamic_deps = [
      # "//bazel/swsscommon:swsscommon_shared",
      "@sonic_swss_common//:libswsscommon_archive",
    ],
    deps = [
      # "tests_deps_wrapper",
       ":fake_response_publisher_lib",
       "//cfgmgr:cfgmgr_base_lib",
       "//lib:lib_utils",
       "//orchagent:orchagent_test_lib",
       "//warmrestart:warmrestartassist_lib",
       "@com_google_googletest//:gtest",
       "@com_google_googletest//:gtest_main",
       "//bazel/hiredis:hiredis",
       "//bazel/libnl3:libnl-genl-3",
       "//bazel/libnl3:libnl-route-3",
       "//bazel/libnl3:libnl-nf-3",
       "//bazel/libnl3:libnl3",
       "//bazel/saimetadata:saimeta",
       "//bazel/saimetadata:saimetadata",
       "//bazel/saivs:saivs",
       "//bazel/zmq:zmq",

       # TODO BL: Figure out why we must depend on these wodeps directly and the -rpaths are not baked into the binary
       "@@rules_distroless++apt+bookworm_libnl-3-200-amd64_3.7.0-0.2-b1//:libnl-3-200_wodeps",
       "@@rules_distroless++apt+bookworm_libnl-nf-3-200-amd64_3.7.0-0.2-b1//:libnl-nf-3-200_wodeps",
       "@@rules_distroless++apt+bookworm_libnl-3-dev-amd64_3.7.0-0.2-b1//:libnl-3_wodeps",
       "@@rules_distroless++apt+bookworm_libnl-genl-3-dev-amd64_3.7.0-0.2-b1//:libnl-genl-3_wodeps",
       "@@rules_distroless++apt+bookworm_libnl-nf-3-dev-amd64_3.7.0-0.2-b1//:libnl-nf-3_wodeps",
       "@@rules_distroless++apt+bookworm_libnl-route-3-dev-amd64_3.7.0-0.2-b1//:libnl-route-3_wodeps",
       "@@rules_distroless++apt+bookworm_libhiredis-dev-amd64_0.14.1-3//:libhiredis_wodeps",
       "@@rules_distroless++apt+bookworm_libhiredis0.14-amd64_0.14.1-3//:libhiredis0.14_wodeps",

       # TODO BL: new deps
       "@bookworm//libyang2-dev:libyang2",

       # "@sonic_swss_common//:boost",
       # "@bookworm//libboost-serialization-dev:libboost-serialization",
       # "@bookworm//libboost-serialization1.74-dev:libboost-serialization1.74",
       "@@rules_distroless++apt+bookworm_libboost-serialization1.74-dev-amd64_1.74.0-ds1-21//:libboost-serialization1.74_wodeps",
    ],
    # TODO BL: figure out what to do with these.
    additional_linker_inputs = [
      "@@rules_distroless++apt+bookworm_libboost-serialization1.74-dev-amd64_1.74.0-ds1-21//:usr/lib/x86_64-linux-gnu/libboost_serialization.so",
      "@@rules_distroless++apt+bookworm_libboost-serialization1.74-dev-amd64_1.74.0-ds1-21//:usr/lib/x86_64-linux-gnu/libboost_wserialization.so",
    ]
)

# only works with --config=portsyncd_tests_opts
cc_test(
    name = "portsyncd_tests",
    srcs = [
        "portsyncd/portsyncd_ut.cpp",
    ],
    copts = COMMON_COPTS,
    linkopts = COMMON_LINKOPTS,
    deps = [
        ":common_test_lib",
        ":fake_response_publisher_lib",
        "//lib:lib_utils",
        "//portsyncd:portsyncd_lib",
    ],
)

cc_test(
    name = "intfmgrd_tests",
    srcs = [
        "intfmgrd/intfmgr_ut.cpp",
    ] + ALL_TEST_HDRS,
    copts = COMMON_COPTS,
    linkopts = COMMON_LINKOPTS,
    deps = [
        ":common_test_lib",
        ":fake_response_publisher_lib",
    ],
)

# todo(lmeninato): only works in kokoro
cc_test(
    name = "teammgrd_tests",
    srcs = [
        "teammgrd/teammgr_ut.cpp",
    ] + ALL_TEST_HDRS,
    copts = COMMON_COPTS,
    linkopts = COMMON_LINKOPTS,
    deps = [
        ":common_test_lib",
        ":fake_response_publisher_lib",
    ],
)

cc_test(
    name = "fpmsyncd_tests",
    srcs = [
        "fpmsyncd/test_fpmlink.cpp",
        "fpmsyncd/test_routesync.cpp",
    ] + ALL_TEST_HDRS,
    copts = COMMON_COPTS,
    linkopts = COMMON_LINKOPTS,
    deps = [
        ":common_test_lib",
        ":fake_response_publisher_lib",
        "//fpmsyncd:fpmsyncd_lib",
    ],
)

cc_test(
    name = "response_publisher_tests",
    srcs = [
        "response_publisher/response_publisher_ut.cpp",
    ] + ALL_TEST_HDRS,
    copts = COMMON_COPTS,
    linkopts = COMMON_LINKOPTS,
    deps = [
        ":common_test_lib",
        "//orchagent:response_publisher_lib",
        "//bazel/saimetadata:saimeta",
        "//bazel/saimetadata:saimetadata",
    ],
)
