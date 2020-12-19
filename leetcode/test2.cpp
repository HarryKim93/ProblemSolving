# sub nested_prefix_insert {
#     for ($size = 0; $size < $prefix_size; $size++) {
#         $cmd = "set pname$size:foo 0 0 7"; $val = "fooval$size"; $rst = "STORED";
#         mem_cmd_is($sock, $cmd, $val, $rst);
#         for ($csize = 0; $csize < $cprefix_size; $csize++) {
#             $cmd = "set pname$size:cpname$csize:foo 0 0 8"; $val = "fooval$size$csize"; $rst = "STORED";
#             mem_cmd_is($sock, $cmd, $val, $rst);
#         }
#     }
# }

# sub nested_item_get_hit {
#     for ($size = 0; $size < $prefix_size; $size++) {
#         $cmd = "get pname$size:foo";
#         $rst = "VALUE pname$size:foo 0 7\nfooval$size\nEND";
#         mem_cmd_is($sock, $cmd, "", $rst);
#         for ($csize = 0; $csize < $cprefix_size; $csize++) {
#             $cmd = "get pname$size:cpname$csize:foo";
#             $rst = "VALUE pname$size:cpname$csize:foo 0 8\nfooval$size$csize\nEND";
#             mem_cmd_is($sock, $cmd, "", $rst);
#         }
#     }
# }

# sub count_total_prefix_exist {
# 	print $sock "stats detail dump\r\n";
# 	my $line = scalar <$sock>;
# 	$count = 0;
# 	while ($line =~ /^PREFIX/) {
# 		$count = $count + 1;
# 		$line = scalar <$sock>;
# 	}
#   	if ($count != $prefix_size) {
#     	croak("The number of prefixes is incorrect.");
#   	}
# }

# sub prefix_flush {
# 	for ($size = 0; $size < $prefix_size; $size++) {
# 		$cmd = "flush_prefix pname$size"; $rst = "OK";
# 		mem_cmd_is($sock, $cmd, "", $rst);
# 	}
# }

# sub child_prefix_flush {
#     for ($size = 0; $size < $prefix_size; $size++) {
#       	for ($csize = 0; $csize < $cprefix_size; $csize++) {
# 			$cmd = "flush_prefix pname$size:cpname$csize"; $rst = "OK";
# 			mem_cmd_is($sock, $cmd, "", $rst);
# 		}
#     }
# }

# sub check_all_child_prefixes_flushed {
#     for ($size = 0; $size < $prefix_size; $size++) {
#         for ($csize = 0; $csize < $cprefix_size; $csize++) {
#             $cmd = "get pname$size:cpname$csize:foo";
#             $rst = "END";
#             mem_cmd_is($sock, $cmd, "", $rst);
#         }
#     }
# }

# sub check_all_prefixes_flushed {
#     for ($size = 0; $size < $prefix_size; $size++) {
#         $cmd = "get pname$size:foo";
#         $rst = "END";
#         mem_cmd_is($sock, $cmd, "", $rst);
#     }
# }

# sub check_prefix_count_0 {
# 	print $sock "stats detail dump\r\n";
# 	my $line = scalar <$sock>;
# 	$count = 0;
# 	while ($line =~ /^PREFIX/) {
# 		$count = $count + 1;
# 		$line = scalar <$sock>;
# 	}
# 	if ($count != 0) {
# 		croak("The number of prefixes is incorrect.");
# 	}
# }

# # LOB test sub routines
# sub lop_insert {
#     my ($key, $from, $to, $create) = @_;
#     my $index;
#     my $vleng;
#     for ($index = $from; $index <= $to; $index++) {
#         $val = "datum$index";
#         $vleng = length($val);
#         if ($index == $from) {
#             $cmd = "lop insert $key $index $vleng $create";
#             $rst = "CREATED_STORED";
#         } else {
#             $cmd = "lop insert $key $index $vleng";
#             $rst = "STORED";
#         }
#         mem_cmd_is($sock, $cmd, $val, $rst);
#     }
# }

# sub sop_insert {
#     my ($key, $from, $to, $create) = @_;
#     my $index;
#     my $vleng;
#     for ($index = $from; $index <= $to; $index++) {
#         $val = "datum$index";
#         $vleng = length($val);
#         if ($index == $from) {
#             $cmd = "sop insert $key $vleng $create";
#             $rst = "CREATED_STORED";
#         } else {
#             $cmd = "sop insert $key $vleng";
#             $rst = "STORED";
#         }
#         mem_cmd_is($sock, $cmd, $val, $rst);
#     }
# }